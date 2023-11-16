#include <ivy_filter.h>

IvyFilter::IvyFilter(int num_hashes) : num_hashes_(num_hashes) {
    hash_family_ = new HashFamily(num_hashes_);
}

void IvyFilter::Add(const std::string& key) {
    for (int i = 0; i < num_hashes_; i++) {
        bitArray.set(hash_family_->hash(key, i) % bit_set_size);
    }
}

auto IvyFilter::Contains(const std::string& key) -> bool {
    for (int i = 0; i < num_hashes_; i++) {
        if (!bitArray.test(hash_family_->hash(key, i) % bit_set_size)) {
            return false;
        }
    }
    return true;
}

void IvyFilter::Remove(const std::string& key) {
    for (int i = 0; i < num_hashes_; i++) {
        bitArray.reset(hash_family_->hash(key, i) % bit_set_size);
    }
}

std::string IvyFilter::ToString() {
    return bitArray.to_string();
}

auto IvyFilter::GetSize() -> size_t {
    return bitArray.count();
}