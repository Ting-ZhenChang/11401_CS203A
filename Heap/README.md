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
