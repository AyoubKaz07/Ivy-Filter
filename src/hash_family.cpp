#include <hash_family.h>
#include <string>
#include <MurmurHash3.h>


// WARNING TEST OUT THE HASH FUNCTIONS' DISTRIBUTION OF VALUES
HashFamily::HashFamily(int numHashes) {
    for (size_t seed = 0; seed < numHashes; seed++) {
            hash_family_.emplace_back([seed](const std::string& key_) {
            uint32_t hash_result_;
            MurmurHash3_x86_32(key_.c_str(), static_cast<int>(key_.length()), static_cast<uint32_t>(seed), &hash_result_);
            return static_cast<size_t>(hash_result_);
        });
    }
}

size_t HashFamily::hash(const std::string& key, int i) const {
    return hash_family_[i](key);
}