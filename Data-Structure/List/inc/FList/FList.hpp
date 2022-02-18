
#ifndef FLIST_HEADER_H
#define FLIST_HEADER_H

#include "FNode.hpp"


template <typename T>
class Forward_List
{
public:
    Forward_List();
    ~Forward_List();

    template <typename ARG_TYPE>
    void push_front(ARG_TYPE value);

    void pop_front();

    void clear() noexcept;

    bool empty() const noexcept;

    T* begin() noexcept;

    T* end() noexcept;

private:
    Forward_Node<T>* startPtr;
    Forward_Node<T>* endPtr;

};

#include "./../../src/FList/FList.cpp"

#endif