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





# Heap（Max-Heap & Min-Heap）
  
基本定義
- Heap 是一種 Complete Binary Tree（完全二元樹）
- 常用 Array 儲存:
  - 節省空間
  - 方便存取父子節點

Array Index 關係（0-based）:
- Parent(i) = (i - 1) / 2
- Left Child(i) = 2i + 1
- Right Child(i) = 2i + 2

heap性質需要注意:
- Heap 一定是 Complete Binary Tree，但 不一定是 BST
- 常使用 tmp 變數進行交換（swap）
- Heap 僅保證 父子關係大小，不保證左右子樹排序
  

  Max-Heap 性質:
  - 每個節點的值 大於等於其子節點
  - Root 為最大值
  - 插入元素後需執行 Bubble Up（向上調整）

  Max-Heap 範例:

           60
          /    \
         5      40
        / \    /
      30  20  10

      - 滿足 Complete Binary Tree
      - 父節點 ≥ 子節點


  Min-Heap 性質:
  - 每個節點的值 小於等於其子節點
  - Root 為最小值
  - 插入元素後需執行 Bubble Up（向上調整）

  非合法 Min-Heap範例（不完整）:
   
            2
          /   \
         5     8
        / \     \
       9  12    30
     
       - 不符合 Complete Binary Tree（右子樹有節點，但左子樹未填滿）
       - 因此 不能稱為 Heap

Max-Heap 插入與建堆

範例一: 插入 13 到 Max-Heap

         20
        /  \
      13   19
     /  \   / \
    7   3  5

      - 插入 13：
      
           20
          /  \
        13   19
       /  \   / \
      7   3  5  13
      
    - 插入 10：
    
            20
           /  \
         13   19
        /  \   / \
       7   3  5  13
      /
    10
- 插入時根據 Complete Binary Tree 的性質，新節點一定插在最底層最左邊的空位。

 範例二：插入 30 並進行 Heapify

         20
        /  \
      15   13
     /  \   / \
    7   3  5  10

    - 插入 30：
 
            20
           /  \
         15   13
        /  \   / \
       7   3  5  10
      /
    30

    - Heapify 後：

            30
           /  \
         20   13
        /  \   / \
       15  3  5  10
      /
     7

刪除Min-Heap & Max-Heap的root:
- 刪除根節點（Root）
- 將最後一個節點移到根的位置
- 進行 Heapify（向下調整）以維持 Heap 性質


Min-Heap刪除範例:

          2
         / \
       5   4
      / \   \
    26 19  13
    
    - 刪除根節點 2 → 將 13 移到根 → Heapify 後：
        
          4
         / \
       5   13
      / \
    26 19

Min-Heap刪除範例:

          80
         /  \
       50    60
      / \   / \
     20 40 30 100
     
    - 刪除根節點 80 → 將 100 移到根 → Heapify 後：
      
          100
         /   \
       50     60
      / \    /
     20 40  30

    - 刪除後的陣列表示：
    [100, 50, 60, 20, 40, 30] 
    原本的最大值 80 已移除，100 成為新根。


## 建堆（Build Heap）時間複雜度比較

| 方法              | 說明                         | 時間複雜度   | 備註               |
|-------------------|------------------------------|--------------|--------------------|
| Repeated Insert   | 逐一 insert + bubble up      | O(n log n)   | 直觀但較慢         |
| Bottom-up Heapify | 從最後一個非葉節點往下調整   | O(n)         | 最常用、最有效率   |


## Heap 操作時間複雜度比較表

| 操作         | Max-Heap     | Min-Heap     |
|--------------|--------------|--------------|
| Insert       | O(log n)     | O(log n)     |
| Delete Root  | O(log n)     | O(log n)     |
| Get Root     | O(1)         | O(1)         |
| Build Heap   | O(n)         | O(n)         |


# AVL Tree

定義 :
- AVL Tree 是一種自平衡的 Binary Search Tree（BST）。
- 在 插入/刪除 操作下，越平衡（高度越低），效率越高。
- BST 的 worst case 是 skewed tree，時間複雜度為 O(n)。
- AVL Tree 因為保持平衡，不會出現 O(n) 的情況。

平衡因子（Balance Factor）:
- 定義：hL - hR（左子樹高度 - 右子樹高度）
- 成為 AVL Tree 的前提是先為 BST。
- 每個節點的平衡因子必須在 [-1, 0, 1] 範圍內。
- 若高度為 h 的 AVL Tree，其最多節點數為：F_{h+2}-1 （F 為 Fibonacci 數列）

結構:

           D
          / \
         L   R
       (hL)   (hR)


範例一：合法 AVL Tree

          20
         /  \
       15    32
      /  \
     8    18

範例二：非法 AVL Tree

          30
         /  \
       15    40
      /  \
     8    22
           \
           28

- 問題：節點 28 < 30，但未放在左子樹 → 違反 BST 性質 → 此非 AVL Tree ❌


AVL Tree 建構範例：
插入序列 [2, 5, 8, 10, 1, 3, 15]
給定數列：2, 5, 8, 10, 1, 3, 15
請依序插入並建構 AVL Tree。

    2
     \
      5
       \
        8


- 插入順序造成右傾（skewed）結構。
- 不符合 AVL Tree 的平衡性。

中間結果：部分平衡（比較平衡）

        5
       / \
      2   8
     / \    \
    1   3    10
             \
              15

- 插入後進行部分旋轉與重構。
- 雖然比原始 BST 更平衡，但仍未達到最佳 AVL 結構。

最終結果：完全平衡 AVL Tree（平衡後）

        5
       / \
      2   10
     / \  / \
    1  3 8  15

- 每個節點的平衡因子皆在 [-1, 0, 1] 範圍內。
- 完整符合 AVL Tree 的定義。


## Linked list、array、AVL tree時間複雜度比較表

| 操作類型             | 陣列（Array）                     | 鍊結串列（Linked List） | AVL 樹（AVL Tree）     |
|----------------------|----------------------------------|--------------------------|------------------------|
| 搜尋 X               | 可用 binary search → `O(log n)`  | 須逐一比對 → `O(n)`      | 平衡搜尋 → `O(log n)`  |
| 搜尋第 k 個元素      | 直接索引 → `O(1)`                 | 須走訪 k 次 → `O(k)`     | 須走訪 → `O(log n)`    |
| 插入 X               | 插入後須整體位移 → `O(n)`         | 插入節點 → `O(1)`        | 平衡插入 → `O(log n)`  |
| 刪除第 k 個元素      | 刪除後須位移 `n-k` 次 → `O(n-k)`  | 須走訪 k 次 → `O(k)`     | 平衡刪除 → `O(log n)`  |
| 依序輸出             | 須逐一走訪 → `O(n)`               | 須逐一走訪 → `O(n)`      | 中序走訪 → `O(n)`      |


## 整理: B.S.T、AVL Tree、Heap time complexity 

| Table Size (m)               |             beat case        |      worse case                |
|------------------------------|------------------------------|--------------------------------|      
|  B.S.T                       |            o(logn)           |  o(n)(斜曲樹時)                 |
|  AVL                         |            o(logn)           |  NO(解決不平衡，故無worse case)  |
|  haep                        |      insert = o(logn)        |  找最大值 = o(1)                |



# Red-Black Tree（紅黑樹）

紅黑樹性質與目的:
- 在和AVL Tree時間複雜度相同的情況下，紅黑數rotation的次數比較小
- 每個節點不是 紅色（R） 就是 黑色（B）
- Root 一定是黑色
- 所有外部節點皆為黑色
- 不能連續紅色

插入基本規則:
- 新插入的節點 一律為紅色（RED）
- 插入後若違反紅黑樹性質 → 需要 調整（Fix-up）
  - 調整方式包含：
    - Color Change（重新著色, C.C.）
    - Rotation（旋轉）：LL / RR / LR / RL


範例一:
插入順序: 4, 7, 12, 15, 3, 5, 14, 18
```text

(1) 插入 4
   樹為空 → 4 成為 root
   Root 必須是黑色

    4(B)

 (2) 插入 7
   7 為紅色，父節點 4 為黑色 → 合法

    4(B)
      \
       7(R)

 (3) 插入 12
   出現 RR case（右右）
   Uncle 為 NIL（黑） → Left Rotation + Recolor

     7(B)
     /   \
   4(R) 12(R)

 (4) 插入 15
   父節點 12 為紅，Uncle 4 為紅 → Color Change

      7(B)
     /   \
   4(B) 12(B)
            \
            15(R)

 (5) 插入 3、5
   插入後仍滿足性質（父為黑）

          7(B)
         /    \
      4(B)   12(B)
     /   \       \
   3(R) 5(R)     15(R)

(6) 插入 14
  出現 RL case（Right-Left）
  先 Right Rotation，再 Left Rotation

         7(B)
       /     \
    4(B)    14(B)
   /   \    /   \
 3(R) 5(R) 12(R) 15(R)

(7) 插入 18
  父 15 為紅，Uncle 12 為紅 → Color Change

        7(B)
       /     \
    4(B)    14(R)
   /   \    /   \
 3(R) 5(R) 12(B) 15(B)
                      \
                      18(R)

```
# GRAPH
## Adjacency List

特性: 有 n 個頂點，有 n 條 linked list

無向圖:

<img width="876" height="558" alt="image" src="https://github.com/user-attachments/assets/8e3e280d-6e66-43a4-a627-0fbc47c64c01" />

Adjacency List:

1 → 2 → Null

2 → 1 → 3 → 4 → Null

3 → 2 → 4 → Null

4 → 2 → 3 → Null

有向圖:

<img width="614" height="624" alt="image" src="https://github.com/user-attachments/assets/52808b66-4226-44ba-a3dc-b424cc6e9836" />

Adjacency List:

1 → 3 → Null

2 → 1 → 3 → Null

3 → Null


## Adjacency Matrix

無向圖:

<img width="876" height="558" alt="image" src="https://github.com/user-attachments/assets/8e3e280d-6e66-43a4-a627-0fbc47c64c01" />

Adjacency Matrix:

|   | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| 1 | 0 | 1 | 0 | 0 |
| 2 | 1 | 0 | 1 | 1 |
| 3 | 0 | 1 | 0 | 1 |
| 4 | 0 | 1 | 1 | 0 |

有向圖:

<img width="614" height="624" alt="image" src="https://github.com/user-attachments/assets/52808b66-4226-44ba-a3dc-b424cc6e9836" />

Adjacency Matrix:

|   | 1 | 2 | 3 |
|---|---|---|---|
| 1 | 0 | 1 | 0 |
| 2 | 1 | 0 | 1 |
| 3 | 0 | 0 | 0 |

## 時間複雜度

|                        | adj matrix      | adj list        |
|------------------------|-----------------|-----------------|
| 空間複雜度              |  O(n²)          | O(n + e)        |
| 檢查邊是否存在           |  o(1)          | o(e)             |
| 求某頂點 degree         |  O(n)          | O(e) / O(n+e)     |
| 適合情況               | 完全圖           | 連通圖            |



## Adjacency Matrix vs Adjacency List

| 項目 | Adjacency Matrix | Adjacency List |
|----|----|----|
| Vertex 數影響 | ❌ 空間與 V² 成正比 | ✅ 與 V 成正比 |
| Edge 數影響 | ❌ 不影響空間 | ✅ 與 E 成正比 |
| Check edge (u, v) | ✅ **O(1)** | ❌ **O(deg(u))** |
| 計算總邊數 | ❌ **O(V²)** | ✅ **O(V + E)** |
| 鄰居查找 | ❌ **O(V)** | ✅ **O(deg(v))** |
| BFS / DFS | ❌ **O(V²)** | ✅ **O(V + E)** |
| Space | ❌ 較浪費 | ✅ 較節省 |
| 插入 / 刪除邊 | ❌ O(1) 但浪費空間 | ✅ **O(1)** |
| Random access | ✅ O(1) | ❌ 不支援 |
| Dense / Sparse | **Dense graph** | **Sparse graph** |
| 重點計算單位 | 以 **Vertex** 為主 | 以 **Edge** 為主 |
| 典型應用 | Small board game | Social network、Google Maps、Dijkstra、Kruskal |


<img width="2048" height="1152" alt="image" src="https://github.com/user-attachments/assets/3e5d859a-4f3f-445d-9d90-5b77f27fe3f4" />


## BFS / DFS

在無向的前提下:
  - BFS需要用一個visited array儲存，因為level order可能會重疊，用queue來儲存(FIFO)。
  - DFS用Stack來儲存 (stack是存visited，且需要搜尋最長路徑，會把短路徑放到最後才pop)。

若有向: 
  - 需要討論方向性和weight。


## graph / tree
|                        | tree             | graph          |
|------------------------|-----------------|-----------------|
| 連通                    |  一定          | 不一定           |
| cycle                   |  無            | 有             |
| degree                 |  有             | 無             |
| Traversal              |  無visited      | 有visited       |


## Best / Worst Case

**Best case：如果為 Connected graph**

edge = n - 1

O(n + e) = O(n + n - 1) < O(n²)

→ 故用 adjacency list 較好

---

**Worst case：如果為 complete graph**

edge = n(n - 1) / 2

O(n + e) = O(n + n(n - 1)/2) > O(n²)

→ 故用 adjacency matrix 較好




## Graph traversal Algorithms

概念:
- 初始將所有節點 visited 設為 false
- 從起始點 v 開始，標記為 true
- 遍歷所有相鄰節點 w
- 若 w 尚未被訪問，則以 w 為起點遞迴呼叫 DFS
- 若最後仍有節點 visited = false，代表圖不連通
    
```text
visited[1...n] := false
v 為起始節點

procedure DFS(v: integer)
var w: integer;
begin
  visited[v] := true;
  for each w ∈ adj(v) do
    if not visited[w] then
      DFS(w);
end
```




## Breadth-First Search (BFS)

概念:
- 適用於無權重且無向圖，可用來求最短路徑長度
- 使用 Queue 進行層層擴展
- 每次從 Queue 前端取出節點 u，將其相鄰且未訪問的節點 v：
- 標記為灰色（已發現）
- 設定距離 d[v] = d[u] + 1
- 設定父節點 π[v] = u
- 加入 Queue
- 最後將 u 標記為黑色（已完成）

```text
BFS(s: Start Vertex)
{
  for each u ∈ G.V - {s} do
  {
    color[u] = white;
    d[u] = ∞;
    π[u] = null;
  }
  color[s] = gray;
  d[s] = 0;
  π[s] = null;
  create Q;
  Enqueue(Q, s);

  while (Q ≠ null) do
  {
    u = Dequeue(Q);
    for each v ∈ adj(u) do
    {
      if (color[v] == white) then
      {
        color[v] = gray;
        d[v] = d[u] + 1;
        π[v] = u;
        Enqueue(Q, v);
      }
    }
    color[u] = black;
  }
}
```


## DFS with Cycle Detection (Back Edge)

概念:
- 在 DFS 過程中，若遇到 Back Edge（從灰色節點指向另一灰色節點），代表存在環（Cycle）
- 使用顏色標記節點狀態：
- white: 未訪問
- gray: 正在訪問中
- black: 已完成訪問

```text
DFS(G)
{
  for each vertex u ∈ G.V do
  {
    color[u] = white;
    π[u] = null;
  }
  Time = 0;
  for each vertex u ∈ G.V do
    if (color[u] == white)
      DFS-Visit(u);
}

DFS-Visit(u)
{
  color[u] = gray;
  Time = Time + 1;
  d[u] = Time;

  for each v ∈ adj(u) do
  {
    if (color[v] == white)
    {
      π[v] = u;
      DFS-Visit(v);
    }
    else if (color[v] == gray)
    {
      // Back Edge detected → Cycle exists
    }
  }

  color[u] = black;
  Time = Time + 1;
  f[u] = Time;
}
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
