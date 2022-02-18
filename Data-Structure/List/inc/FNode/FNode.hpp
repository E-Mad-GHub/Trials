
#ifndef FNODE_HEADER_H
#define FNODE_HEADER_H

template <typename DATA_TYPE>
class Forward_Node
{

public:

    Forward_Node(); 

    ~Forward_Node(); 

    inline bool setNextPtr(const Forward_Node *ptr);

    inline Forward_Node* getNextPtr() const;

    inline bool setData(const DATA_TYPE *dataPtr);

    inline bool setData(const DATA_TYPE &dataPtr);

    inline bool setData(DATA_TYPE &&dataRVal);

    inline DATA_TYPE* getData() const;

private:
    Forward_Node *nextPtr;
    DATA_TYPE *dataPtr;

};

#include "./../../src/FNode/FNode.cpp"

#endif