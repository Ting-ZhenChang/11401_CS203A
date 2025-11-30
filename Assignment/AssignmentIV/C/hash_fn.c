/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    更動interger的部分，用黃金比例A = (sqrt(5) - 1) / 2 ≈ 0.6180339887查看分布

   Development History:
    - 2025/11/18: Initial implementation
    - 2025/11/24: Refactored to use hash_fn.h
    - 2025/11/30: include References 

   Developer: Ting-ZhenChang <Sofe231436935@gmail.com>
 */

    //References:
        // Donald E. Knuth, The Art of Computer Programming, Volume 3: Sorting and Searching.Section 6.4 — “Hashing by Multiplication”.
        // https://github.com/Code42Cate/The-Art-of-Computer-Programming/blob/master/Volume3.pdf
        // Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein,Introduction to Algorithms (CLRS), Chapter 11 — “Hash Functions”, string hashing discussion.
        // Polynomial rolling hash.” Wikipedia, The Free Encyclopedia.


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