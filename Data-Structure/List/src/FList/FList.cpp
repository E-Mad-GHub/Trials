#include <iostream>


template <typename T>
Forward_List<T>::Forward_List(): startPtr(nullptr), endPtr(nullptr)
{

}

template <typename T>
Forward_List<T>::~Forward_List()
{
    this->clear();
}

template <typename T>
template <typename ARG_TYPE>
void Forward_List<T>::push_front(ARG_TYPE value)
{
    Forward_Node<T>* tmpPtr = new Forward_Node<T>;

    tmpPtr->setData(value);

    tmpPtr->setNextPtr(nullptr);
    
    if(this->startPtr)
    {
        this->endPtr->setNextPtr(tmpPtr);
        this->endPtr = tmpPtr;
    }
    else
    {
        this->startPtr = tmpPtr;
        this->endPtr = tmpPtr;
    }
}

template <typename T>
void Forward_List<T>::pop_front()
{
    if(nullptr != this->startPtr)
    {
        if(this->endPtr == this->startPtr)
        {
            delete this->endPtr;

            this->startPtr = nullptr;
            this->endPtr = nullptr;
        }
        else
        {

            Forward_Node<T>* tmpPtr = this->startPtr;

            while(tmpPtr->getNextPtr() != this->endPtr)
            {
                tmpPtr = tmpPtr->getNextPtr();
            }

            delete this->endPtr;

            this->endPtr = tmpPtr;
        }
    }
}

template <typename T>
void Forward_List<T>::clear() noexcept
{
    if(this->startPtr)
    {
        while (nullptr != this->startPtr)
        {
            Forward_Node<T>* temp = this->startPtr->getNextPtr();
            delete this->startPtr;
            this->startPtr = temp;   
        }

        this->endPtr = nullptr;
    }
}

template <typename T>
bool Forward_List<T>::empty() const noexcept
{
    bool returnVal = true;

    if(this->startPtr)
    {
        returnVal = false;
    }

    return returnVal;
}

template <typename T>
T* Forward_List<T>::begin() noexcept
{   
    T* returnPtr = nullptr;

    if(this->startPtr)
    {
        returnPtr = this->startPtr->getData();
    }

    return returnPtr;
}

template <typename T>
T* Forward_List<T>::end() noexcept
{
    T* returnPtr = nullptr;

    if(this->endPtr)
    {
        returnPtr = this->endPtr->getData();
    }

    return returnPtr;
}