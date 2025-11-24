/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    更動Non-interger的部分，用Polynomial Rolling Hash實作查看分布

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/21: Refactored to use hash_fn.h

   Developer: Ting-ZhenChang <Sofe231436935@gmail.com>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    
    return key % m;  
}

int myHashString(const char* str, int m) {

    if (m <= 0 || str == NULL) return 0;
    unsigned long hash = 0;
    // TODO: replace with your own design
    return (int)(hash % m); // basic division method
}