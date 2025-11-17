# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer:  Ting-ZhenChang
Email: Sofe231436935@gmail.com

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  [Your implementation here]
  ```
- Rationale: [Explain your design choices and how they minimize collisions.]

### Non-integer Keys
- Formula / pseudocode:
  ```text
  [Your implementation here]
  ```
- Rationale: [Explain your approach and its effectiveness for non-integer keys.]

## Experimental Setup
- Table sizes tested (m): 64, 11, 37
- Test dataset:
  - Integers: 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 200, 204, 208, 212, 216, 220, 224, 228, 232, 236
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

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
  

- Example output for strings:

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=64): [36, 40, 44, 48, 52, 56, 60, 0, 4, 8, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44]
  Hash table (m=11): [9, 0, 4, 8, 12, 3, 7, 3, 7, 11, 2, 6, 5, 9, 0, 4, 8, 12, 3, 7 ,11, 2]
  Hash table (m=37): [26, 30 ,34, 1, 5, 9, 13, 17, 21, 25, 15, 19, 23, 27, 31, 25, 2, 6, 10 ,14]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: 從Example output for integers，可以看出在非質數不能保持平均分布，且如果m是二次方，分布較差 ; m是質數則較平均。從%10時也有明顯pattern，index太集中。

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
