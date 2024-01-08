#pragma once

#include <vector>
#include <string>
#include "hash_family.h"

class IvyFilter {
public:
    IvyFilter(int num_hashes, int size) : hash_family_(new HashFamily(num_hashes)), size_(size), num_hashes_(num_hashes) {
        // Initialize the bit set with zeros
        bit_set_.resize(size, 0);
    }

    void Add(const std::string& key);
    auto Contains(const std::string& key) -> bool;
    void Remove(const std::string& key);
    auto GetSize() const -> int { return size_; }
    auto GetNumHashes() const -> int { return num_hashes_; }
    auto GetBitSet() const -> const std::vector<int>& { return bit_set_; }

private:
    HashFamily* hash_family_;
    int size_;
    std::vector<int> bit_set_;
    int num_hashes_;
};
