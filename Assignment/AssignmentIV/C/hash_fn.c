/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    更動interger的部分，用黃金比例A = (sqrt(5) - 1) / 2 ≈ 0.6180339887查看分布

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/24: Refactored to use hash_fn.h

   Developer: Ting-ZhenChang <Sofe231436935@gmail.com>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    double A = 0.6180339887;   
    double frac = key * A - (int)(key * A);
    return (int)(m * frac);
}


int myHashString(const char* str, int m) {
    if (m <= 0 || str == NULL) return 0;

    unsigned long hash = 0;
    unsigned long p = 31;   

    while (*str) {
        hash = hash * p + (*str);
        str++;
    }

    return (int)(hash % m);
}