#pragma once

#include <functional>
#include <string>
#include <vector>

class HashFamily {
public:
    HashFamily(int numHashes);
    size_t hash(const std::string& key, int i) const;

private:
    std::vector<std::function<size_t(const std::string&)>> hash_family_;
};