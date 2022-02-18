
#ifndef FLIST_HEADER_H
#define FLIST_HEADER_H

#include "FNode.hpp"

template <typename T>
class Forward_List
{
public:
    // Constructor
    Forward_List();

    // Destructor
    ~Forward_List();

    // Pushes new data to the front of the list
    template <typename ARG_TYPE>
    void push_front(ARG_TYPE value);

    // removes the front data of the list
    void pop_front();

    // Clears the list
    void clear() noexcept;

    // Checks whether the list is empty or not
    bool empty() const noexcept;

    // Returns a pointer to the begining node
    T* begin() noexcept;

    // Returns a pointer to the last node
    T* end() noexcept;

private:
    // The start of the list pointer
    Forward_Node<T>* startPtr;

    // The end of the list pointer
    Forward_Node<T>* endPtr;

};

#include "./../../src/FList/FList.cpp"

#endif