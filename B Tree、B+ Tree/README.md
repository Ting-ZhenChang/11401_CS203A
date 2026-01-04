## 前言: 有了BST / AVL / Red-Black Tree 後，為什麼一定要有 B-Tree / B+-Tree ?
- 因為資料不在記憶體，而是在磁碟（Disk / SSD）上，B-Tree / B+-Tree 是為了 「減少磁碟 I/O 次數」 而生的。

## m-way Search Tree
- 定義: 一種「多叉搜尋樹」
- Tree Degree = m（m > 2）
- 每個節點最多有：
  - m 個 children
  - m − 1 個 keys（data）
- 節點結構:
  - Key 數量
  - 每個節點最多 m − 1 個 key
  - key 在節點內是排序好的
- Child 數量
  - 若節點有 k 個 key，會有 k + 1 個 children
  - 最大情況：key = m − 1，child = m

 所以m-way Search Tree 是 Binary Search Tree 的推廣，透過提高節點分支度，使樹高度顯著降低，
特別適合用於外部儲存裝置上的搜尋與排序，能有效減少磁碟 I/O 次數，也是 B-Tree 與 B+-Tree 的理論基礎。

# B Tree
- B-Tree 是一種 Balanced m-way Search Tree
- 為 Disk / External Storage 設計的搜尋樹
- 每個節點可存放多個 key 與 child pointer
- 目的：降低樹高度，減少 I/O 次數
- Root 至少有 2 個 children
- 對於 非 root、非 leaf 的 internal node：
  - child 數量介於: ⌈m/2⌉∼m
- 每個 node 的：key 數量 = child 數 − 1
  -  即介於: ⌈m/2⌉−1∼m−1
- 所有 leaf node 一定在同一層，一定是 height-balanced
- 2-3-4 Tree degree 介於 ⌈4/2⌉∼4=2∼4 之間
- 2-3 Tree degree 介於 ⌈3/2⌉∼3=2∼3 之間
- Insert / Delete 較複雜，Data 可能存在於 non-leaf node(失敗節點)，不像 B+ Tree data 只在 leaf 且 internal node 只存 index

```text

範例一: 不是 B-Tree

        [20 | 30]
       /    |    \
      5    25    40
     / \    |      \
    2  7   28      45

False，不是 B-Tree。
因為 Leaf nodes 不在同一層，且違反 B-Tree 的「高度平衡」性質

範例二: 2-3-4 Tree

          [10 | 20 | 30]
        /      |      |      \
       5      15     25      35

True。
符合：
  m = 4
  key 數 ≤ 3  
  所有 leaf 在同一層


範例三: 2-3 Tree

        [20 | 30]
       /     |     \
     10     25     35

True。
符合：
  m = 3
  key 數 ≤ 2
  高度平衡

```

## B Tree 的insert、delete 

```text

範例: B-Tree of order 3（2-3 Tree）
依序插入：38、55、37

B-Tree child 數量範圍：⌈m/2⌉∼m = 2∼3
B-Tree key 數量範圍：(child−1) = 1∼2

初始樹結構:
            [30]
           /    \
        [20]    [40]
       /    \   /    \
 [10,15]   [25] [35,38] [45,50]


(1) Insert 38:

            [30]
           /    \
        [20]    [40]
       /    \   /    \
 [10,15]   [25] [35,38] [45,50]

此為合法 B-Tree

(2) Insert 55:

Step 1：插入到 leaf
[45,50] → [45,50,55]  ❌ overflow


Step 2：Split leaf node
中間 key：50
50 往上提（promote）
分裂為：
  left：[45]
  right：[55]


            [30]
           /    \
        [20]   [40,50]
       /    \   /   |   \
 [10,15] [25] [35,38] [45] [55]

此為合法 B-Tree

(3) Insert 37:

Step 1：插入 leaf
[35,38] → [35,37,38]  ❌ overflow

Step 2：Split leaf
中間 key：37
37 往上提

            [30]
           /    \
        [20]   [37,40,50]  ❌ overflow


Step 3：Internal Node Split
中間 key：40
40 往上提到 root
分裂為：
  left child：[37]
  right child：[50]


最終結果:

              [30,40]
            /     |      \
         [20]   [37]    [50]
        /   \   /   \   /   \
 [10,15] [25] [35] [38] [45] [55]

```
詳細版流程圖:


![83560](https://github.com/user-attachments/assets/4203b9e7-83cc-443b-838d-c5e01d7c9d6b)

```text
給定一棵 2–3 Tree
依序刪除以下 key：58、65、55、50

B-Tree child 數量範圍：⌈m/2⌉∼m = 2∼3
B-Tree key 數量範圍：(child−1) = 1∼2

初始樹結構:

                [50]
              /      \
           [30]     [60 | 70]
          /   \     /   |    \
       [10]  [40] [55|58] [65] [75|80]

(1) Delete 58:

                [50]
              /      \
           [30]     [60 | 70]
          /   \     /   |    \
       [10]  [40]   [55]   [65] [75|80]

58 位於葉節點 [55 | 58]，刪除後仍符合 2–3 tree 規則。

(2) Delete 65:

刪除後會造成中間子樹不平衡，因為 75 不在 60～70 區間內，需進行 rotate。

調整後:
                [50]
              /      \
           [30]     [60 | 75]
          /   \     /   |    \
       [10]  [40]  [55]  [70]  [80]


(3) Delete 55:

55 位於 leaf node [55]，刪除後造成中間子樹不平衡，需要調整結構

調整後：

                [50]
              /      \
           [30]       [75]
          /    \     /    \
       [10]  [40] [60 | 70] [80]

(4) Delete 50:

50 位於 root
策略：
  找左子樹最大值 or 右子樹最小值來取代

此例選擇 右子樹最小值 (75)
（左子樹最大值 40 不適合，否則會造成結構高度不一致）

調整後結果：

                [75]
              /      \
           [30]      [80]
          /    \     /
       [10]  [40] [70]


```
詳細版流程圖:


![53031](https://github.com/user-attachments/assets/0edcf0ab-ca59-4fa3-9801-cfafcf52d3e2)

# B+ Tree
- 分成索引層和資料層
  - 索引層: index B-Tree
  - 資料層: data block 用 linked list
- 所有data都在leaf
- insert、delete 容易，需要index
- 支援ISAM
  
## B+ Tree的insert、delete 

範例一: B+ Tree of order 3，insert 8 ?


![45035](https://github.com/user-attachments/assets/32c420da-f450-43f4-b4b3-fca624c954c9)


範例二:  B+ Tree of order 3，依序刪除以下key: 8、100、10、5 ?


![7476](https://github.com/user-attachments/assets/652d7e4e-5fd8-4261-98b4-24c398e60947)


