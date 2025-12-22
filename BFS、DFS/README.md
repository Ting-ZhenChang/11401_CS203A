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
