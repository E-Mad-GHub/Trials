#include <iostream>

// Constructor
template <typename DATA_TYPE>
Forward_Node<DATA_TYPE>::Forward_Node(): nextPtr(nullptr), dataPtr(new DATA_TYPE)
{

}

// Destructor
template <typename DATA_TYPE>
Forward_Node<DATA_TYPE>::~Forward_Node()
{
    delete dataPtr;
}

// Setter for the "nextPtr"
template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setNextPtr(const Forward_Node *ptr)
{
    nextPtr = (Forward_Node *)(ptr);  
}

// Getter for the "nextPtr"
template <typename DATA_TYPE>
Forward_Node<DATA_TYPE>* Forward_Node<DATA_TYPE>::getNextPtr() const
{
    return this->nextPtr; 
}

// Setter for the Node data "dataPtr"
template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setData(const DATA_TYPE *dataPtr)
{
    *(this->dataPtr) = (*dataPtr);
}

// Setter for the Node data "dataPtr" (overload)
template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setData(const DATA_TYPE &dataRef)
{
    *(this->dataPtr) = dataRef;
}

// Setter for the Node data "dataPtr" (overload)
template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setData(DATA_TYPE &&dataRVal)
{
    *(this->dataPtr) = dataRVal;
}

// Getter for the node data "dataPtr"
template <typename DATA_TYPE>
DATA_TYPE* Forward_Node<DATA_TYPE>::getData() const
{
    return this->dataPtr;
}
