- **11401_CS203A**
- **姓名:** 張婷媜
- **學號:** 1112463
## 課程資訊
- **課程名稱:** 資料結構
- **授課教師:** 黃鈺峰老師
- **課號:** CS203A
- **學分數:** 3
- **學期長度:** 18周 
- **上課時間:**
  - 禮拜一 9:10-10:00
  - 禮拜二 15:10~17:00

## 課程目的
- 本課程重點介紹資料結構的核心概念，說明資料結構與演算法之間的密切關係，以及它們如何影響記憶體的使用與管理。課程內容涵蓋 linked lists、stacks、graphs、hashing 與 arrays 等主題，透過這些資料結構的學習，幫助我們理解並掌握其基本操作與應用方式。
- 深入理解各種搜尋與排序的演算法和時間複雜度。此筆記強調在熟悉資料結構後，立即搭配演算法練習，因此在每一個章節中皆會搭配 Pseudocode，以提升問題分析與解決的能力，我認為此方法是一種相當高效的學習方式。
- 參考資料: Fundamentals of Data Structures in C by Ellis Horowitz, Sartaj Sahni, Susan Anderson-Freed

## 課程描述
- 9/9
  - C 的資料結構 = 記憶體操作，資料結構主在於讓記憶體空間最小化。因為工程師需要自己負責記憶體配置和釋放，雖然效率高、可預測性強，但需要自行管理，若錯誤會造成記憶體洩漏或程式崩潰。
  - 程式的資料都必須存放在記憶體中才能被處理。記憶體包含:Variables、Data structures、Temporary buffers，資料越動態、越複雜 → 記憶體管理的重要性越高。
  - 指標是儲存變數或物件的記憶體位址，協助記住每一筆資料放在哪裡。指標讓程式設計師直接操作記憶體 → 強大但危險，需要小心避免 memory leak & crash
  - 效能考量：記憶體區塊的擺放方式會影響快取與存取效率
  - 學習價值：打好基礎，能進行低階除錯與安全的記憶體操作
  - 5H1W
    - What
      - 用什麼形式去保存與組織，讓data更有效率
    - Why
      - 取資料有效率，不同資料結構取決於不同演算法，用最少最短的記憶體時間
    - When
      - 快速查找可以用hash、tree可以用大型資料庫儲存、queue可以讓cpu分時處理達到多功能
    - Where
      - os、AL&ML、database
    - Who
      - 學生、軟體工程師、研究演算法的人
    - How
      - 學會挑選合適的資料結構和演算法，在多人使用下，用好的演算法來加速運算和管理。查詢、insert、delete、update都有不同資料結構
  - Jave為了解決machine code問題(不相容)，會用bytecode經過vm，再轉成Machine code
    
## 課程大綱

|  |
| ------- |
| [Array、linked list](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Array%E3%80%81linked%20list) |
| [Stack、Queue](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Stack%E3%80%81Queue) |
| [Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Tree) |
| [Binary Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Binary%20Tree) |
| [Binary Search Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Binary%20Search%20Tree) |
| [AVL Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/AVL%20Tree) |
| [Rad Black Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Rad%20Black%20Tree) |
| [Heap](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Heap) |
| [Graph](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Graph) |
| [BFS、DFS](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/BFS%E3%80%81DFS) |
| 作業心得與整理: [Assignment V Reflection](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Assignment%20V%20Reflection) |
| 自主學習: [森林化為二元樹之方法](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/%E6%A3%AE%E6%9E%97%E8%BD%89%E6%88%90%E4%BA%8C%E5%85%83%E6%A8%B9%E4%B9%8B%E6%96%B9%E6%B3%95) 、 [B Tree、B+ Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/B%20Tree%E3%80%81B%2B%20Tree)、[Extended Binary Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Extended%20Binary%20Tree) 、[Expression Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Expression%20Tree)、[Thread Binary Tree](https://github.com/Ting-ZhenChang/11401_CS203A/tree/main/Thread%20Binary%20Tree)|

# Tree Structures Overview

 ```text

  Tree
└── B.T (Binary Tree)
    ├── 搜尋用途 → B.S.T (Binary Search Tree)
    │   ├── 左右大小 → 數據搜尋
    │   └── Extended B.T
    │       └── Heap (double-ended priority queue DS)
    │           ├── Min-Heap / Max-Heap
    │           ├── Deep / Shallow
    │           └── Huffman Tree
    │               └── Optional B.S.T (Optimal B.S.T)
    └── 完全 B.T (Complete Binary Tree)

AVL Tree (高度平衡)
└── 外部加權 → Weight External Path Length
    └── R.B Tree (Red-Black Tree)
        └── B Tree
            └── B⁺ Tree（資料儲存在下方）

Min Heap / Max Heap
Deep Heap / Shallow Heap
Huffman Tree（可視為 Optimal B.S.T)

Other Trees / Heaps
├── Splay Tree
├── Leftist Heap
├── Binomial Heap
└── Fibonacci Heap

```


