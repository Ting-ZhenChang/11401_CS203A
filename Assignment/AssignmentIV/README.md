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
- Rationale:
- 1. 使用Knuth的乘法法，能在非質數table size下也保持相對均勻分布，避免 division method % m 在 m=10 這種情況造成明顯pattern，讓 key 的每一個 bit 都能「均勻擴散」到 hash 結果中，使得鄰近的 key 產生完全不同的 index。
  2. Knuth 在 The Art of Computer Programming 中證明，使用此 A 可以在一般情況下得到近似均勻分布的 hash 結果，故使用 Knuth 推薦的常數 A（黄金比例倒數），能避免 key 在二進位表示上出現規律時造成 clustering
  3. 計算成本非常低，不需要額外儲存表格、不需要 prime，適合 integer key
    - reference: Donald E. Knuth, The Art of Computer Programming, Volume 3: Sorting and Searching.Section 6.4 — “Hashing by Multiplication”.
    - https://github.com/Code42Cate/The-Art-of-Computer-Programming/blob/master/Volume3.pdf

### Non-integer Keys
- Formula / pseudocode:
  ```text
   hash = 0
  for each char c in string:
    hash = hash * 31 + c
  return hash % m
  ```
- Rationale:
- 1. 每次都乘上一個固定的31倍數，這樣做的好處是，前面字元的影響會被放大，後面字元也能持續影響結果，整個雜湊值就不會集中在某些範圍，而是比較平均地分散在整個表格裡
  2. 字元序列（字串）天然適合用 polynomial hash，因為每加入一個字元時讓前面結果乘以一個固定基底 p（常用 31、53），此assignment選擇 p = 31
  3. Polynomial rolling hash 證明了可以降低 collision，並已廣泛使用
    - reference: Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein,Introduction to Algorithms (CLRS), Chapter 11 — “Hash Functions”, string hashing       discussion.
    - Polynomial rolling hash.” Wikipedia, The Free Encyclopedia.

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
| 10             | 9, 5, 2, 8, 4, 0, 6, 3, 9, 5, 5, 1, 7, 3, 9, 6, 2, 8, 4, 0                  | 分布呈現明顯週期性         |
| 11             | 10, 6, 2, 9, 4, 0, 7, 3, 10, 5, 5, 1, 8, 4, 10, 6, 2, 9, 5, 0               | 整體分布比 m=10 均勻       |
| 37             | 36, 22, 7, 30, 16, 2, 25, 11, 34, 20, 19, 5, 27, 13, 36, 22, 8, 31, 17, 3   | 分布最均勻且無明顯週期性    | 



## Compilation, Build, Execution, and Output

### Compilation
- 本專案在 Windows 環境下使用 makefile.bat 進行編譯
 
  ```bash
  # Build both C and C++ versions
  makefile.bat all 
  
  # Build only C version
  makefile.bat c 
  
  # Build only C++ version
  makefile.bat cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  
  ```bash
  gcc -std=c11 -Wall -Wextra -Wpedantic -g -o C\hash_function.exe C\main.c C\hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++17 -Wall -Wextra -Wpedantic -g -o CXX\hash_function_cpp.exe CXX\main.cpp CXX\hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  Makefile.bat clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  .\C\hash_function.exe
  ```
  or
  ```bash
  .\CXX\hash_function_cpp.exe
  ```

### Result Snapshot
- Example output for integers:
<img width="848" height="896" alt="image" src="https://github.com/user-attachments/assets/bc2946a7-5554-4604-bcb2-2ae9a3e93415" />
<img width="746" height="812" alt="image" src="https://github.com/user-attachments/assets/ee03cef6-82f9-4d36-b321-45da4ac6a23c" />
<img width="684" height="822" alt="image" src="https://github.com/user-attachments/assets/7e52106c-619f-4f70-93c2-9a35e9c8c838" />

- Example output for strings:
<img width="796" height="1456" alt="image" src="https://github.com/user-attachments/assets/a347325e-f762-495b-b620-115b8593cc71" />

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
在這次實驗中，我使用乘法法來處理整數鍵、Polynomial Rolling Hash 來處理字串鍵，並比較它們在不同 table size 下的分布情況。從結果來看，雜湊函數本身的設計固然重要，但「m 是否為質數」其實更影響整體表現。特別是在 m=37 時，不論是整數還是字串的分布都相對平均；相反地，m=10 或 m=11 時明顯更容易發生模式性重複與碰撞。

- 與原本 example 比較的反思
  課堂 example 的整數 hash 分布幾乎呈現很明顯的規律性，例如：m=10 時呈現「1,2,3…9,0」這種周期性循環 ; 字串的 example 則全部輸出 0，代表 hash function 沒有效把字元資訊混合進去
  相比之下，我的hash function可以看到:
    - 1. 整數 hash 透過乘法法能打破簡單的線性模式
      2. 字串的 Polynomial Rolling Hash 能成功讓不同字變成不同 index，不再全部落在 0
      3. m 設為質數時，分布比課堂 example 平均得多，所以代表原本 example 過於簡單，只是示範概念，並不具備實作上的實用性。而實際設計 hash function 時，必須考慮是整數還是字串型態、字元權重、bit mixing、避免 overflow、以及參數的選擇、table size等等

- 未來的改善空間
  - 1. 如果目標是用於開放位址法，可以試著加入課程中提到過的二階 hash，能有效降低二次探測的 clustering 問題
    2. 字串 hash 的 unsigned long 在較長字串下可能會 overflow，可以改用unsigned long long，改善大數 overflow 風險，以增加 hash 的穩定性
    3. 測試字串與整數量偏少，可以更系統性的測試方式，例如用隨機產生大量整數測試
