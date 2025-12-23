#include <omnetpp.h>
#include "BlockchainMsg_m.h"
#include <string>
#include <functional> 

using namespace omnetpp;

class UserNode : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    std::string calculateHash(std::string data);
};

Define_Module(UserNode);

void UserNode::initialize() {
    // Schedule first transaction randomly
    scheduleAt(simTime() + uniform(1, 5), new cMessage("generateTx"));
}

void UserNode::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        TransactionMsg *tx = new TransactionMsg("NewTransaction");
        tx->setSenderId(getId());
        tx->setReceiverId(intuniform(0, 10)); 

        // 1. Set the REAL amount first
        double realAmount = uniform(10, 100);
        tx->setAmount(realAmount);
        tx->setTimestamp(simTime().str().c_str());
        
        // 2. Generate the Valid Hash for this amount
        std::string rawData = std::to_string(tx->getSenderId()) + std::to_string(realAmount);
        tx->setTransactionHash(calculateHash(rawData).c_str());

        // --- HACKER LOGIC START ---
        // 20% chance to tamper with the data (Simulate an attack)
        if (uniform(0, 1) < 0.2) {
            EV << "!!! HACKER ALERT !!! User " << getId() << " is tampering with the data!" << endl;

            // Change the amount to something huge AFTER hashing
            tx->setAmount(1000000.0);

            EV << "   Original Amount: " << realAmount << endl;
            EV << "   Tampered Amount: 1000000.0" << endl;
            EV << "   (The Hash will no longer match!)" << endl;
        } else {
             EV << "User generating valid transaction..." << endl;
             EV << "   Data: " << rawData << endl;
        }
        // --- HACKER LOGIC END ---

        EV << "   Sent Hash: " << tx->getTransactionHash() << endl;

        // 3. Send to connected nodes
        int n = gateSize("port");
        for (int i = 0; i < n; i++) {
            send(tx->dup(), "port$o", i);
        }
        delete tx; 

        // Schedule next transaction
        scheduleAt(simTime() + uniform(2, 10), msg);
    } else {
        delete msg;
    }
}

std::string UserNode::calculateHash(std::string data) {
    std::hash<std::string> hasher;
    size_t hash = hasher(data);
    return std::to_string(hash);
}
