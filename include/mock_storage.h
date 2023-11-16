#pragma once

#include <map>
#include <vector>
#include <cstdint>
#include <stdexcept>

class MockStorage {
public:
    // Write data to the storage
    void write(const std::string& key, const std::vector<uint8_t>& data);

    // Read data from the storage
    std::vector<uint8_t> read(const std::string& key) const;

    // Check if a key exists in the storage
    bool contains(const std::string& key) const;

    // Remove a key from the storage
    void remove(const std::string& key);

private:
    std::map<std::string, std::vector<uint8_t>> storage;
};