#include "mock_storage.h"

void MockStorage::write(const std::string& key, const std::vector<uint8_t>& data) {
    storage[key] = data;
}

std::vector<uint8_t> MockStorage::read(const std::string& key) const {
    auto it = storage.find(key);
    if (it != storage.end()) {
        return it->second;
    } else {
        throw std::out_of_range("Key not found");
    }
}

bool MockStorage::contains(const std::string& key) const {
    return storage.find(key) != storage.end();
}

void MockStorage::remove(const std::string& key) {
    storage.erase(key);
}