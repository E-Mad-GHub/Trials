

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
custom::unordered_map<KEY, VALUE, MAX_SIZE>::unordered_map()
{
    // Init the vector which is the main container. This needs to be optimized.
    keyValContainer.reserve(MAX_SIZE);

    for(auto &x : keyValContainer)
    {
        x.occupied = false;
    }
}

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
custom::unordered_map<KEY, VALUE, MAX_SIZE>::~unordered_map()
{
    this->clear();
}

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
bool custom::unordered_map<KEY, VALUE, MAX_SIZE>::empty() const noexcept
{
    for(auto &x : keyValContainer)
    {
        if(true == x.occupied)
        {
            return false;
        }
    }

    return true;
}

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
void custom::unordered_map<KEY, VALUE, MAX_SIZE>::clear() noexcept
{
    for(auto &x : keyValContainer)
    {
        if(true == x.occupied)
        {
            delete x.keyValuePtr;
        }
    }
}





template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
template<class... Args>
std::pair<std::pair<KEY, VALUE> *,bool> custom::unordered_map<KEY, VALUE, MAX_SIZE>::emplace(Args&&... args)
{
    std::pair<std::pair<KEY, VALUE> *,bool> returnVal;
    std::size_t tmpOrder = 0;
    bool done = false;

    returnVal.first  = nullptr;
    returnVal.second = false;

    std::pair<KEY, VALUE>* tmpPtr = new std::pair<KEY, VALUE>(std::forward<Args>(args)...);

    std::size_t tmpIndex = ((hasher(tmpPtr->first)) % MAX_SIZE);


    // This need to handle the saving of the shifted elements in the original elements
    // And their deletion too FUCK
    while((!done) && (tmpOrder < MAX_SIZE))
    {
        if(false == keyValContainer[tmpIndex + tmpOrder].occupied)
        {
            keyValContainer[tmpIndex].occupied    = true;
            keyValContainer[tmpIndex].order       = tmpOrder;
            keyValContainer[tmpIndex].keyValuePtr = tmpPtr;
            done = true;
        }
        else
        {
            ++tmpOrder;
        }
    }

    if(done)
    {
        returnVal.first  = tmpPtr;
        returnVal.second = true;
    }

    return returnVal;
}

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
size_type custom::unordered_map<KEY, VALUE, MAX_SIZE>::size() const noexcept
{

}

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
size_type custom::unordered_map<KEY, VALUE, MAX_SIZE>::max_size() const noexcept
{
    return MAX_SIZE;
}

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE>
size_type custom::unordered_map<KEY, VALUE, MAX_SIZE>::erase( const KEY& key )
{

}


