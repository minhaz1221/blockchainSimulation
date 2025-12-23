#include <omnetpp.h>
#include "BlockchainMsg_m.h"
#include <string>
#include <functional>

using namespace omnetpp;

class MinerNode : public cSimpleModule {
  private:
    cQueue pendingTxs;       // The "Mempool"
    bool isMining;           // Status flag
    int blocksMinedCount;    // Counter for graph generation

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    bool verifyHash(TransactionMsg *tx);
    void mineBlock();
};

Define_Module(MinerNode);

void MinerNode::initialize() {
    isMining = false;
    blocksMinedCount = 0; // Reset counter at start
    WATCH(isMining); 
    WATCH(blocksMinedCount);
}

void MinerNode::handleMessage(cMessage *msg) {
    // Case 1: Mining is finished (Self-message)
    if (msg->isSelfMessage() && strcmp(msg->getName(), "MineComplete") == 0) {
        EV << "Block Mined successfully! Adding to Ledger." << endl;
        bubble("Block Mined!");

        // --- DATA RECORDING FOR GRAPH ---
        blocksMinedCount++;
        // This saves the data to the results file for your .anf graph
        recordScalar("Blocks Mined", blocksMinedCount);
        // --------------------------------

        // Visual: Turn Green to show success
        getDisplayString().setTagArg("i", 1, "green");

        isMining = false;
        delete msg;
    } 
    // Case 2: Received a new transaction
    else if (dynamic_cast<TransactionMsg*>(msg)) {
        TransactionMsg *tx = (TransactionMsg*)msg;
        
        // 1. Verify Hash (Authentication)
        if (verifyHash(tx)) {
            EV << "Transaction Verified. Added to Mempool." << endl;
            pendingTxs.insert(tx);
            
            // Start mining if we have enough transactions (>=2) and aren't busy
            if (!isMining && pendingTxs.getLength() >= 2) {
                mineBlock();
            }
        } else {
            EV << "Fake transaction detected! Discarding." << endl;
            delete tx;
        }
    }
}

bool MinerNode::verifyHash(TransactionMsg *tx) {
    // Re-calculate the hash to verify integrity
    std::string rawData = std::to_string(tx->getSenderId()) + std::to_string(tx->getAmount());
    std::hash<std::string> hasher;
    std::string calculatedParams = std::to_string(hasher(rawData));

    // --- HASH LOGGING ---
    EV << "Miner received transaction. Verifying..." << endl;
    EV << "   Received Hash:   " << tx->getTransactionHash() << endl;
    EV << "   Calculated Hash: " << calculatedParams << endl;

    bool isMatch = (calculatedParams == tx->getTransactionHash());

    if (isMatch) {
        EV << "   Result: MATCH (Authentic)" << endl;
    } else {
        EV << "   Result: MISMATCH (Fake)" << endl;
    }
    // --------------------

    return isMatch;
}

void MinerNode::mineBlock() {
    isMining = true;

    // Visual: Turn Gold while working
    getDisplayString().setTagArg("i", 1, "gold");

    EV << "Mining started... solving Proof of Work..." << endl;

    // Simulate mining delay (Proof of Work)
    scheduleAt(simTime() + 1.5, new cMessage("MineComplete"));
}
