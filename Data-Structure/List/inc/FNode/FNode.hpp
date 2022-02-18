
#ifndef FNODE_HEADER_H
#define FNODE_HEADER_H

template <typename DATA_TYPE>
class Forward_Node
{

public:

    // Constructor
    Forward_Node(); 

    // Destructor
    ~Forward_Node(); 

    // Setter for the "nextPtr"
    inline bool setNextPtr(const Forward_Node *ptr);

    // Getter for the "nextPtr"
    inline Forward_Node* getNextPtr() const;

    // Setter for the Node data "dataPtr"
    inline bool setData(const DATA_TYPE *dataPtr);

    // Setter for the Node data "dataPtr" (overload)
    inline bool setData(const DATA_TYPE &dataPtr);

    // Setter for the Node data "dataPtr" (overload)
    inline bool setData(DATA_TYPE &&dataRVal);

    // Getter for the node data "dataPtr"
    inline DATA_TYPE* getData() const;

private:
    // The next pointer of the node
    Forward_Node *nextPtr;

    // The data pointer of the node
    DATA_TYPE *dataPtr;

};

#include "./../../src/FNode/FNode.cpp"

#endif