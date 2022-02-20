
#include <boost/container_hash/hash.hpp>
#include <vector>

#ifndef UMAP_HEADER_H
#define UMAP_HEADER_H

typedef std::size_t size_type;

namespace custom
{

template <typename KEY, typename VALUE>
struct pairUnit
{
    std::pair<KEY, VALUE> *keyValuePtr;
    bool  occupied;
    unsigned long int order;
};

template <typename KEY, typename VALUE, unsigned long int MAX_SIZE=10>
class unordered_map
{
public:

    unordered_map();
    ~unordered_map();

    template<class... Args>
    std::pair<std::pair<KEY, VALUE> *,bool> emplace(Args&&... args);

    bool empty() const noexcept;

    size_type size() const noexcept;

    size_type max_size() const noexcept;

    size_type erase( const KEY& key );

    void clear() noexcept;

private:

    // The container
    std::vector<pairUnit<KEY, VALUE>> keyValContainer;

    // The hasher function
    boost::hash<KEY> hasher;
};

}

#include "./../../src/unordered-map/umap.cpp"

#endif