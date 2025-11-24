# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Ting-ZhenChang  
Email: Sofe231436935@gmail.com  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  h(k) = floor( m * ( (k * A) mod 1 ) )
  where A = (sqrt(5) - 1) / 2 ≈ 0.6180339887
  ```
- Rationale: 使用Knuth的乘法法，能在 非質數table size下也保持相對均勻分布，避免 division method % m 在 m=10 這種情況造成明顯pattern。

### Non-integer Keys
- Formula / pseudocode:
  ```text
   hash = 0
  for each char c in string:
    hash = hash * 31 + c
  return hash % m
  ```
- Rationale: 每次都乘上一個固定的33倍數，這樣做的好處是，前面字元的影響會被放大，後面字元也能持續影響結果，整個雜湊值就不會集中在某些範圍，而是比較平均地分散在整個表格裡。

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) |                             Index Sequence                                  |       Observation        |
|----------------|-----------------------------------------------------------------------------|--------------------------|
| 10             | 9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0                  | Pattern repeats every 10 |
| 11             | 10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0               | More uniform             |
| 37             | 36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3   | Near-uniform             | 



## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

### Result Snapshot
- Example output for integers:
<img width="920" height="1544" alt="螢幕擷取畫面 2025-11-24 123735" src="https://github.com/user-attachments/assets/82a0cc57-0dcf-4da6-96aa-e41710497ebe" />
<img width="542" height="742" alt="螢幕擷取畫面 2025-11-24 123824" src="https://github.com/user-attachments/assets/3823cd1b-c551-435b-ba5d-b9000ec6f29e" />


- Example output for strings:
<img width="710" height="1329" alt="螢幕擷取畫面 2025-11-24 123847" src="https://github.com/user-attachments/assets/27298088-9df5-4336-8416-4f01d5b48467" />


- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 0, 1, 2, 3, 4, 5]
  Hash table (m=37): [21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23]
  ```
- Design Function output for integers:
  ```
  Hash table (m=10): [9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0]
  Hash table (m=11): [10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0]
  Hash table (m=37): [36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Design Function output for strings:
 ```
  Hash table (m=10): ["cat=2", "dog=4", "bat=1", "cow=9", "ant=3", "owl=8", "bee=0", "hen=5", "pig=0", "fox=3"]
  Hash table (m=11): ["cat=10", "dog=6", "bat=6", "cow=7", "ant=9", "owl=6", "bee=5", "hen=5", "pig=0", "fox=9"]
  Hash table (m=37): ["cat=27", "dog=3", "bat=28", "cow=20", "ant=25", "owl=23", "bee=26", "hen=29", "pig=27", "fox=18"]
  ```
- Observations:
- 原始範例的 string hash分布全為0可以看出不為最好的hash function，原本 example 中的 string hash 過於簡化，幾乎沒有對字元做有效運算，導致所有字串都被映射到同一個index，形成極端的 clustering。
- 裡用Polynomial Rolling Hash 改善了字串分布，此例利用 base = 31 可以發現對字母序列造成差異化，避免全為0的分布，但還是某些key會造成collision(m=11); table size的設定很重要，m的不同可能會讓分布完全不同，經由此觀察，m是二次方時容易放大 hash 值中的特定位元，導致集中且分布差，當m是質數時，通常較為平均。
- 原始 integer example 呈現較週期性pattern，而用乘法的方式能讓分布較分散，尤其在 m = 37 時效果更佳，說明乘法法能有效打散連續 key 的規律性，比單純mod更能降低規律分布問題。

## Analysis
- Prime vs non-prime `m`: 當 m 為質數（如 11, 37）時，hash 分布通常較為均勻分布到各bucket，因此collision 較少 ; 當m不是質數或2的次方（如 m=10），容易出現規律性pattern，使部分bucket過度集中。
- Patterns or collisions: 從結果可以知道，hash function的設計會影響Patterns和collisions，像用Polynomial Rolling Hash 利用字元位置與乘法加權，就可以有效區分不同的字串，讓collisions降低，但即使使用較佳的hash方法也並不是完美的，若大小選擇不當，還是會有碰撞，顯示m的結構對效能產生很大的影響。
- Improvements: 使用質數作為hash table較好，並搭配好的hash function，可有效減少碰撞並提升效率。

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
