#include "ivy_filter.h"
#include "hash_family.h"
#include "mock_storage.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief This file contains unit tests for the IvyFilter class, which is a Bloom filter implementation.
 * 
 * The tests cover the insertion, lookup, and removal of elements from the filter (false positives, false negatives)
 *  
 */

// BLOOM FILTER USES 
#define num_hashes 3

TEST(BloomFilter, Insertion) {
    IvyFilter bloom_filter(num_hashes, 20);

    int num_elems = 1000;
    std::vector<int> keys(num_elems - 1);
    

    for (const auto& key : keys) {
        bloom_filter.Add(std::to_string(key));
    }

    for (const auto& key : keys) {
        EXPECT_EQ(bloom_filter.Contains(std::to_string(key)), true);
    }
}

TEST(BloomFilter, Removal) {
    IvyFilter bloom_filter(num_hashes, 20);

    int num_elems = 1000;
    std::vector<int> keys(num_elems - 1);
    

    for (const auto& key : keys) {
        bloom_filter.Add(std::to_string(key));
    }

    for (int key = 1; key < num_elems / 2; key++) {
        bloom_filter.Remove(std::to_string(key));
        EXPECT_EQ(bloom_filter.Contains(std::to_string(key)), false);
    }
}

TEST(BloomFilter, FalsePositives) {
    IvyFilter bloom_filter(num_hashes, 20);

    int num_elems = 30;
    std::vector<int> keys(num_elems - 1);
    

    for (const auto& key : keys) {
        bloom_filter.Add(std::to_string(key));
    }

    std::vector<int> missing_keys = {0, 1230, 8464, 1015, 91, 1202, 1203, 1010};

    int false_positives = 0;
    for (const auto& key : missing_keys) {
        if (bloom_filter.Contains(std::to_string(key))) {
            false_positives++;
        }
    }

    float false_positives_rate = static_cast<float>(false_positives) / keys.size();
}
