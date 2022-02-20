
// Constructor
template <typename T>
Forward_List<T>::Forward_List(): startPtr(nullptr), endPtr(nullptr)
{

}

// Destructor
template <typename T>
Forward_List<T>::~Forward_List()
{
    this->clear();
}

// Pushes new data to the front of the list
// T is the list data type
// ARG_TYPE is to delegate the overload of the API to the node overload APIs
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

// removes the front data of the list
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

// Clears the list
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

// Checks whether the list is empty or not
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

// Returns a pointer to the begining node
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

// Returns a pointer to the last node
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