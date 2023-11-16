#pragma once

#include <bitset>
#include <vector>
#include "hash_family.h"

#define bit_set_size 10

class IvyFilter {
public:
    IvyFilter(int num_hashes_);
    void Add(const std::string& key);
    auto Contains(const std::string& key) -> bool;
    void Remove(const std::string& key);
    std::string ToString();
    auto GetSize() -> size_t;

private:
    HashFamily *hash_family_;

    // default size
    std::bitset<bit_set_size> bitArray;
    int num_hashes_;
};
