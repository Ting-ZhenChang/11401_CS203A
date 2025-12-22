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
## 課程描述 
- 本課程讓我們了解什麼是資料結構，它跟演算法之間的關係，以及會如何去影響到記憶體。課程內容包含linked lists, stacks, graphs, hashing, arrays等主題，理解和掌握資料結構的基本操作，學習到問題解決的能力，在每一章節都會加上Pseudocode，以便熟悉整個資料結構。
  
## 課程筆記
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
    
 


- 12/1
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











# Tree 資料結構總整理與實務應用比較

在課堂作業中，整理 Binary Tree 及各種進階樹狀資料結構（BST、AVL Tree、Red-Black Tree、Heap 等）的
**結構特性、實際應用場景與選擇理由**

---

## 1. Binary Tree 與 Complete Binary Tree 的差別與應用

### Binary Tree
**特性**
- 每個節點最多兩個子節點
- 結構沒有任何形狀限制
- 不保證平衡或搜尋效率

**實際應用**
- 階層式資料表示（檔案系統、DOM Tree、組織架構）
- 演算法與遞迴教學
- 樹走訪（Preorder / Inorder / Postorder）示範

**定位**
> Binary Tree 主要用來「表達結構與關係」，而非追求效能。

---

### Complete Binary Tree
**特性**
- 除最後一層外，每層皆為滿
- 最後一層節點向左對齊
- 樹高接近最小值
- 可使用 Array 儲存

**實際應用**
- Heap（Max Heap / Min Heap），滿足Complete Binary Tree用Leaf Nodeinsert、delete的特性
- Priority Queue
- Heap Sort
- 排程系統（CPU scheduling）

**定位**
> Complete Binary Tree 是為了「效能與記憶體效率」而存在的結構。

---

## 2. 為什麼字典、電話簿、使用者資料需要 Binary Search Tree 類結構？

這類資料的共同需求：
- 資料可比較（key-based）
- 需要快速查詢
- 支援插入與刪除
- 需要排序或範圍查詢

Binary Search Tree（BST）提供：
- 有序結構（In-order traversal 可得排序結果）
- 平均搜尋時間 O(log n)
- 動態資料操作能力

---

## 3. Binary Search Tree（BST）的實際應用定位

### BST 的優點
- 結構簡單
- 易於實作與理解
- 可支援基本搜尋、插入、刪除

### BST 的限制
- 無法保證平衡
- 最壞情況會退化為 O(n)
- 不適合大型或正式系統

### 實際應用場景
- 資料結構與演算法教學
- 小型資料量的程式工具
- 程式競賽或原型設計
- 作為 AVL / Red-Black Tree 的概念基礎

**總結**
> BST 在實務中多半不是最終選擇，而是過渡結構與概念模型。

---

## 4. AVL Tree 的應用與定位

**特性**
- 自我平衡 Binary Search Tree
- 任一節點左右子樹高度差 ≤ 1
- 搜尋效能最佳

**實際應用**
- 字典（Dictionary）
- 查詢導向的靜態或半靜態資料庫
- 記憶體內 lookup table

**為什麼適合**
- 查詢遠多於更新
- 需要穩定且最快的搜尋速度

**定位**
> AVL Tree 為了搜尋效能，願意付出較高的更新成本。

---

## 5. Red-Black Tree 的應用與定位

**特性**
- 自我平衡 Binary Search Tree
- 使用紅黑規則維持「近似平衡」
- 樹高最多為 2 × log n
- 插入與刪除旋轉次數較少

**實際應用**
- 電話簿
- 使用者資料管理
- 系統層資料結構
- C++ std::map、Java TreeMap
- Linux Kernel

**為什麼適合**
- 資料高度動態
- 插入與刪除頻繁
- 需要整體效能穩定

**定位**
> Red-Black Tree 不追求最矮，但追求最穩定。

---

## 6. BST、AVL Tree、Red-Black Tree 比較總表

| 結構 | 搜尋速度 | 插入 / 刪除 | 平衡程度 | 實務定位 |
|----|----|----|----|----|
| BST | O(log n) 平均 | 快 | 不保證 | 教學、小型應用 |
| AVL Tree | 最快 | 較慢 | 最嚴格 | 查詢導向系統 |
| Red-Black Tree | 很快 | 最穩定 | 次平衡 | 真實系統主流 |

---

## 7. 為什麼「靜態搜尋」選 Sorted Array + Binary Search？

若資料：
- 不再更新
- 只需要搜尋

則：
- Sorted Array + Binary Search
- 搜尋 O(log n)
- 記憶體連續、cache friendly
- 無指標開銷

相比之下：
- Heap 無法快速搜尋任意元素
- Tree 結構反而增加複雜度

---

## 8. 總結反思（Reflection）

雖然 Binary Search Tree 提供了有序搜尋的基本概念，但在缺乏平衡保證的情況下，並不適合大型或真實系統。實務上會依據資料的更新頻率與效能需求，選擇 AVL Tree 或 Red-Black Tree 作為替代。BST 的主要價值在於教育、概念建構，以及作為進階平衡樹的基礎。

---
