/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    更動Non-interger的部分，用Polynomial Rolling Hash實作查看分布

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/21: Refactored to use hash_fn.hpp

   Developer: Ting-ZhenChang <Sofe231436935@gmail.com>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    
    return key % m;  
}

int myHashString(const std::string& str, int m) {
    if (m <= 0 || str.empty()) return 0;

    unsigned long hash = 0;
    const unsigned long p = 31;
    unsigned long power = 1;

    for (char c : str) {
        hash = (hash + static_cast<unsigned long>(c) * power) % m;
        power = (power * p) % m;
    }

    return static_cast<int>(hash);
}