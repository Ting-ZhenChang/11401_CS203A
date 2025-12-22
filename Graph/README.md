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
