#include <iostream>


template <typename DATA_TYPE>
Forward_Node<DATA_TYPE>::Forward_Node(): nextPtr(nullptr), dataPtr(new DATA_TYPE)
{

}    

template <typename DATA_TYPE>
Forward_Node<DATA_TYPE>::~Forward_Node()
{
    delete dataPtr;
}    

template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setNextPtr(const Forward_Node *ptr)
{
    nextPtr = (Forward_Node *)(ptr);  
}

template <typename DATA_TYPE>
Forward_Node<DATA_TYPE>* Forward_Node<DATA_TYPE>::getNextPtr() const
{
    return this->nextPtr; 
}

template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setData(const DATA_TYPE *dataPtr)
{
    *(this->dataPtr) = (*dataPtr);
}

template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setData(const DATA_TYPE &dataRef)
{
    *(this->dataPtr) = dataRef;
}

template <typename DATA_TYPE>
bool Forward_Node<DATA_TYPE>::setData(DATA_TYPE &&dataRVal)
{
    *(this->dataPtr) = dataRVal;
}

template <typename DATA_TYPE>
DATA_TYPE* Forward_Node<DATA_TYPE>::getData() const
{
    return this->dataPtr;
}
