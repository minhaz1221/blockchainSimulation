message TransactionMsg {
    int senderId;
    int receiverId;
    double amount;
    string timestamp;
    string signature;
    string transactionHash;
}

message BlockMsg {
    string prevBlockHash;
    string merkleRoot;
    int nonce;
    string currentBlockHash;
    bool isVerified;
}
