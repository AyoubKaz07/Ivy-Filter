#include <ivy_filter.h>

void IvyFilter::Add(const std::string& key) {
    for (int i = 0; i < num_hashes_; i++) {
        bit_set_[hash_family_->hash(key, i) % size_] = 1;
    }
}

auto IvyFilter::Contains(const std::string& key) -> bool {
    for (int i = 0; i < num_hashes_; i++) {
        if (!bit_set_[hash_family_->hash(key, i) % size_]) {
            return false;
        }
    }
    return true;
}

void IvyFilter::Remove(const std::string& key) {
    for (int i = 0; i < num_hashes_; i++) {
        bit_set_[hash_family_->hash(key, i) % size_] = 0;
    }
}