//
// Generated file, do not edit! Created by opp_msgtool 6.2 from BlockchainMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "BlockchainMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(TransactionMsg)

TransactionMsg::TransactionMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

TransactionMsg::TransactionMsg(const TransactionMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TransactionMsg::~TransactionMsg()
{
}

TransactionMsg& TransactionMsg::operator=(const TransactionMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TransactionMsg::copy(const TransactionMsg& other)
{
    this->senderId = other.senderId;
    this->receiverId = other.receiverId;
    this->amount = other.amount;
    this->timestamp = other.timestamp;
    this->signature = other.signature;
    this->transactionHash = other.transactionHash;
}

void TransactionMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->senderId);
    doParsimPacking(b,this->receiverId);
    doParsimPacking(b,this->amount);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->signature);
    doParsimPacking(b,this->transactionHash);
}

void TransactionMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->senderId);
    doParsimUnpacking(b,this->receiverId);
    doParsimUnpacking(b,this->amount);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->signature);
    doParsimUnpacking(b,this->transactionHash);
}

int TransactionMsg::getSenderId() const
{
    return this->senderId;
}

void TransactionMsg::setSenderId(int senderId)
{
    this->senderId = senderId;
}

int TransactionMsg::getReceiverId() const
{
    return this->receiverId;
}

void TransactionMsg::setReceiverId(int receiverId)
{
    this->receiverId = receiverId;
}

double TransactionMsg::getAmount() const
{
    return this->amount;
}

void TransactionMsg::setAmount(double amount)
{
    this->amount = amount;
}

const char * TransactionMsg::getTimestamp() const
{
    return this->timestamp.c_str();
}

void TransactionMsg::setTimestamp(const char * timestamp)
{
    this->timestamp = timestamp;
}

const char * TransactionMsg::getSignature() const
{
    return this->signature.c_str();
}

void TransactionMsg::setSignature(const char * signature)
{
    this->signature = signature;
}

const char * TransactionMsg::getTransactionHash() const
{
    return this->transactionHash.c_str();
}

void TransactionMsg::setTransactionHash(const char * transactionHash)
{
    this->transactionHash = transactionHash;
}

class TransactionMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_senderId,
        FIELD_receiverId,
        FIELD_amount,
        FIELD_timestamp,
        FIELD_signature,
        FIELD_transactionHash,
    };
  public:
    TransactionMsgDescriptor();
    virtual ~TransactionMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TransactionMsgDescriptor)

TransactionMsgDescriptor::TransactionMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(TransactionMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TransactionMsgDescriptor::~TransactionMsgDescriptor()
{
    delete[] propertyNames;
}

bool TransactionMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransactionMsg *>(obj)!=nullptr;
}

const char **TransactionMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TransactionMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TransactionMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int TransactionMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_senderId
        FD_ISEDITABLE,    // FIELD_receiverId
        FD_ISEDITABLE,    // FIELD_amount
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_signature
        FD_ISEDITABLE,    // FIELD_transactionHash
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *TransactionMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "senderId",
        "receiverId",
        "amount",
        "timestamp",
        "signature",
        "transactionHash",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int TransactionMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "senderId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "receiverId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "amount") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "signature") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "transactionHash") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *TransactionMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_senderId
        "int",    // FIELD_receiverId
        "double",    // FIELD_amount
        "string",    // FIELD_timestamp
        "string",    // FIELD_signature
        "string",    // FIELD_transactionHash
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **TransactionMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TransactionMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TransactionMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TransactionMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TransactionMsg'", field);
    }
}

const char *TransactionMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransactionMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderId: return long2string(pp->getSenderId());
        case FIELD_receiverId: return long2string(pp->getReceiverId());
        case FIELD_amount: return double2string(pp->getAmount());
        case FIELD_timestamp: return oppstring2string(pp->getTimestamp());
        case FIELD_signature: return oppstring2string(pp->getSignature());
        case FIELD_transactionHash: return oppstring2string(pp->getTransactionHash());
        default: return "";
    }
}

void TransactionMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderId: pp->setSenderId(string2long(value)); break;
        case FIELD_receiverId: pp->setReceiverId(string2long(value)); break;
        case FIELD_amount: pp->setAmount(string2double(value)); break;
        case FIELD_timestamp: pp->setTimestamp((value)); break;
        case FIELD_signature: pp->setSignature((value)); break;
        case FIELD_transactionHash: pp->setTransactionHash((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransactionMsg'", field);
    }
}

omnetpp::cValue TransactionMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderId: return pp->getSenderId();
        case FIELD_receiverId: return pp->getReceiverId();
        case FIELD_amount: return pp->getAmount();
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_signature: return pp->getSignature();
        case FIELD_transactionHash: return pp->getTransactionHash();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TransactionMsg' as cValue -- field index out of range?", field);
    }
}

void TransactionMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderId: pp->setSenderId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_receiverId: pp->setReceiverId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_amount: pp->setAmount(value.doubleValue()); break;
        case FIELD_timestamp: pp->setTimestamp(value.stringValue()); break;
        case FIELD_signature: pp->setSignature(value.stringValue()); break;
        case FIELD_transactionHash: pp->setTransactionHash(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransactionMsg'", field);
    }
}

const char *TransactionMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TransactionMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TransactionMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TransactionMsg *pp = omnetpp::fromAnyPtr<TransactionMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TransactionMsg'", field);
    }
}

Register_Class(BlockMsg)

BlockMsg::BlockMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

BlockMsg::BlockMsg(const BlockMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

BlockMsg::~BlockMsg()
{
}

BlockMsg& BlockMsg::operator=(const BlockMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void BlockMsg::copy(const BlockMsg& other)
{
    this->prevBlockHash = other.prevBlockHash;
    this->merkleRoot = other.merkleRoot;
    this->nonce = other.nonce;
    this->currentBlockHash = other.currentBlockHash;
    this->isVerified_ = other.isVerified_;
}

void BlockMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->prevBlockHash);
    doParsimPacking(b,this->merkleRoot);
    doParsimPacking(b,this->nonce);
    doParsimPacking(b,this->currentBlockHash);
    doParsimPacking(b,this->isVerified_);
}

void BlockMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->prevBlockHash);
    doParsimUnpacking(b,this->merkleRoot);
    doParsimUnpacking(b,this->nonce);
    doParsimUnpacking(b,this->currentBlockHash);
    doParsimUnpacking(b,this->isVerified_);
}

const char * BlockMsg::getPrevBlockHash() const
{
    return this->prevBlockHash.c_str();
}

void BlockMsg::setPrevBlockHash(const char * prevBlockHash)
{
    this->prevBlockHash = prevBlockHash;
}

const char * BlockMsg::getMerkleRoot() const
{
    return this->merkleRoot.c_str();
}

void BlockMsg::setMerkleRoot(const char * merkleRoot)
{
    this->merkleRoot = merkleRoot;
}

int BlockMsg::getNonce() const
{
    return this->nonce;
}

void BlockMsg::setNonce(int nonce)
{
    this->nonce = nonce;
}

const char * BlockMsg::getCurrentBlockHash() const
{
    return this->currentBlockHash.c_str();
}

void BlockMsg::setCurrentBlockHash(const char * currentBlockHash)
{
    this->currentBlockHash = currentBlockHash;
}

bool BlockMsg::isVerified() const
{
    return this->isVerified_;
}

void BlockMsg::setIsVerified(bool isVerified)
{
    this->isVerified_ = isVerified;
}

class BlockMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_prevBlockHash,
        FIELD_merkleRoot,
        FIELD_nonce,
        FIELD_currentBlockHash,
        FIELD_isVerified,
    };
  public:
    BlockMsgDescriptor();
    virtual ~BlockMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(BlockMsgDescriptor)

BlockMsgDescriptor::BlockMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(BlockMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

BlockMsgDescriptor::~BlockMsgDescriptor()
{
    delete[] propertyNames;
}

bool BlockMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BlockMsg *>(obj)!=nullptr;
}

const char **BlockMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *BlockMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int BlockMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int BlockMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_prevBlockHash
        FD_ISEDITABLE,    // FIELD_merkleRoot
        FD_ISEDITABLE,    // FIELD_nonce
        FD_ISEDITABLE,    // FIELD_currentBlockHash
        FD_ISEDITABLE,    // FIELD_isVerified
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *BlockMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "prevBlockHash",
        "merkleRoot",
        "nonce",
        "currentBlockHash",
        "isVerified",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int BlockMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "prevBlockHash") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "merkleRoot") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "nonce") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "currentBlockHash") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "isVerified") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *BlockMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_prevBlockHash
        "string",    // FIELD_merkleRoot
        "int",    // FIELD_nonce
        "string",    // FIELD_currentBlockHash
        "bool",    // FIELD_isVerified
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **BlockMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BlockMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BlockMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BlockMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BlockMsg'", field);
    }
}

const char *BlockMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BlockMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        case FIELD_prevBlockHash: return oppstring2string(pp->getPrevBlockHash());
        case FIELD_merkleRoot: return oppstring2string(pp->getMerkleRoot());
        case FIELD_nonce: return long2string(pp->getNonce());
        case FIELD_currentBlockHash: return oppstring2string(pp->getCurrentBlockHash());
        case FIELD_isVerified: return bool2string(pp->isVerified());
        default: return "";
    }
}

void BlockMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        case FIELD_prevBlockHash: pp->setPrevBlockHash((value)); break;
        case FIELD_merkleRoot: pp->setMerkleRoot((value)); break;
        case FIELD_nonce: pp->setNonce(string2long(value)); break;
        case FIELD_currentBlockHash: pp->setCurrentBlockHash((value)); break;
        case FIELD_isVerified: pp->setIsVerified(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BlockMsg'", field);
    }
}

omnetpp::cValue BlockMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        case FIELD_prevBlockHash: return pp->getPrevBlockHash();
        case FIELD_merkleRoot: return pp->getMerkleRoot();
        case FIELD_nonce: return pp->getNonce();
        case FIELD_currentBlockHash: return pp->getCurrentBlockHash();
        case FIELD_isVerified: return pp->isVerified();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'BlockMsg' as cValue -- field index out of range?", field);
    }
}

void BlockMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        case FIELD_prevBlockHash: pp->setPrevBlockHash(value.stringValue()); break;
        case FIELD_merkleRoot: pp->setMerkleRoot(value.stringValue()); break;
        case FIELD_nonce: pp->setNonce(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_currentBlockHash: pp->setCurrentBlockHash(value.stringValue()); break;
        case FIELD_isVerified: pp->setIsVerified(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BlockMsg'", field);
    }
}

const char *BlockMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr BlockMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void BlockMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    BlockMsg *pp = omnetpp::fromAnyPtr<BlockMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BlockMsg'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

