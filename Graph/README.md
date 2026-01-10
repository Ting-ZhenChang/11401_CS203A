# GRAPH
- 由vertex + edge 形成

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



## Adjacency Matrix 和 Adjacency List 的比較

| 項目 | Adjacency Matrix | Adjacency List |
|----|----|----|
| 空間複雜度  |  O(n²) | O(n + e)  |
| Vertex、edge 數 | vertex 少，edge 多 (Dense graph) | vertex 多，edge 少 (Sparse graph) | 
| Check edge  | O(1) | O(deg(u)) |
| 計算總邊數 | O(V²) | O(V + E) |
| 鄰居查找 | O(V) | O(deg(v)) |
| BFS / DFS | O(V²) | O(V + E) |
| Space | ❌ 較浪費 | ✅ 較節省 |
| 插入 / 刪除邊 |  O(1) 但浪費空間 | O(1) |
| Random access | ✅ O(1) | ❌ 不支援 |
| 重點計算單位 | 以 **Vertex** 為主 | 以 **Edge** 為主 |
| 典型應用 | Small board game | Social network、Google Maps、Dijkstra、Kruskal |
| 適合情況               | 完全圖           | 連通圖            |

<img width="2048" height="1152" alt="image" src="https://github.com/user-attachments/assets/3e5d859a-4f3f-445d-9d90-5b77f27fe3f4" />

Reference: https://www.slideshare.net/slideshow/sparse-graph-and-dense-graph-algorithm-use-for-it-and-advantages-and-their-disadvantages/269708779

```text
*Note:

Best case：如果為 Connected graph
edge = n - 1
O(n + e) = O(n + n - 1) < O(n²)
→ 故用 adjacency list 較好


Worst case：如果為 complete graph
edge = n(n - 1) / 2
O(n + e) = O(n + n(n - 1)/2) > O(n²)
→ 故用 adjacency matrix 較好

```
## BFS / DFS

在無向的前提下:
  - BFS需要用一個visited array儲存，因為level order可能會重疊，用queue來儲存(FIFO)。
  - DFS用Stack來儲存 (stack是存visited，且需要搜尋最長路徑，會把短路徑放到最後才pop)。

若有向: 
  - 需要討論方向性和weight。

| 項目 | BFS | DFS |
|----|----|----|
| 資料結構 | 採Queue | 採Stack |
| 走訪方式 |類似preorder traversal | 類似level order traversal |
| 應用| 檢查圖形是否連通、找出連通元件 | 找圖的spanning Tree、檢查圖是否有cycle |

```text
*Note: 當如果所有頂點沒走訪完代表不連通。
```


## graph 和 tree 的比較
|                        | tree             | graph          |
|------------------------|-----------------|-----------------|
| 連通                    |  一定          | 不一定           |
| cycle                   |  無            | 有             |
| degree                 |  有             | 無             |
| Traversal              |  無visited      | 有visited       |




## Graph traversal 演算法

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
## DFS、BFS traversal

DFS:

```text

若 有多個相鄰 vertex 可走，則 vertex number 較小者優先，使用 Depth-First Search (DFS)?

          1
        /   \
       2     3
      / \   / \
     4   5 6   7
      \  |  |  /
          8

(1) 從 vertex 1 開始，依照 vertex no. 小者優先：
1, 2, 4, 8, 5, 6, 3, 7

(2) 從 vertex 6 開始，依照 vertex no. 小者優先：
6, 3, 1, 2, 4, 8, 5, 7

```
BFS:

```text

          1
        /   \
       2     3
      / \   / \
     4   5 6   7
      \  |  |  /
          8

(1) 若從 vertex 1 開始，依照 vertex no. 小者優先：
1, 2, 3, 4, 5, 6, 7, 8
 
(2) 若從 vertex 5 開始，依照 vertex no. 小者優先：
5, 2, 8, 1, 4, 6, 7, 3

```



## DFS、BFS traversal 演算法

DFS:

```text

For i=1 to n do;
  visited[i] = False;
DFS( V = Starting Node)
  {
    Visited[V] = True;
    {
      for each vertex W adjacent to V do
      if ( not visited [W] ) then DFS(W)  
    }
  }

```

BFS:

```text

For i=1 to n do;
  visited[i] = False;
BFS( V = Starting Node)
  {
    Visited[V] = True;
    CreateQ(Q);
    enqueue(Q,V);
    while ( not Isempty(Q) do )
    {
      V = dequeue(Q);
      for each Vertex W adjacent to V do
      {
          if ( not visited[W] then )
          {
            visited[W] = True;
            Enqueue(Q,W); 
          }
      } 
   }


```
