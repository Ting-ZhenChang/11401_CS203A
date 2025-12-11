<img width="378" height="81" alt="image" src="https://github.com/user-attachments/assets/edb5cb01-0cc5-42ba-a64b-dca628316718" /><img width="688" height="210" alt="image" src="https://github.com/user-attachments/assets/c56f4046-81b2-4320-97c9-f3156e5c3f18" />
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
    
- 9/15
  - 尋找最佳路徑 eg: google map
    - vertex(node)、edge(link/line)
      
- 9/23
  - Array 
    - Array是連續記憶體空間(contiguous memory locations)，time complexity: o(1)

    - size of array分為: 靜態和動態
      - 靜態: 在編譯時陣列大小就決定了，是不能被改變的，存取快速但彈性差
      - 動態: size會在runtime時跟系統要一個空間，使用malloc、realloc時，須注意需要自己管理記憶體，最後必須free掉，否則造成效率低或記憶體外洩

    - Dynamic Array需要知道:
      - malloc / realloc 可能失敗在 C 裡，malloc 或 realloc 失敗時會回傳 NULL。你的程式沒有檢查回傳值，若失敗直接使用會 segmentation fault
      - %p表示print pointer， 需搭配void*，\n表換行
      - stack: 是一個指標指向heap記憶體，不能隨便擴充且會保留原值
      - heap: 用malloc/new要來的動態記憶體，可用free釋放。一般都會在heap區塊後擴充，但如果heap不夠，系統會在heap找一塊更大的空間，把舊資料copy上去，並釋放舊的空間

    - STL(標準模板庫) v.s ADT(抽象資料層面)
      - ATD主要是在理論層面，但不管如何實作。舉例:
        - Stack (堆疊)
          - 操作：push(x)、pop()、top()、isEmpty()
          - 規則：後進先出 (LIFO)
          - 但用陣列還是鏈結串列去實作？ADT 不管。
        - Queue (佇列)
          - 操作：enqueue(x)、dequeue()、front()、isEmpty()
          - 規則：先進先出 (FIFO)

      - STL是用現成的程式庫，以使用者方便為主要目的，可直接編譯，屬於實作層面。舉例:
        - vector → Dynamic Array (動態陣列)
        - list → Linked List (鏈結串列)
        - stack → Stack (堆疊，通常包裝 deque)
        - queue → Queue (佇列，通常包裝 deque)
        - priority_queue → Heap (優先佇列)
        - set / map → 平衡二元搜尋樹 (紅黑樹)
        - unordered_set / unordered_map → Hash Table
      - array v.s vecter
        - array
          - 大小在編譯時就固定
          - 記憶體: stack
          - performance: 快
          - 記憶體容量: 小
          - 彈性差
          - 使用時機: 都是已知的值，適合少資料使用
        - vector
          - 在runtime才設定變數
          - 記憶體: heap
          - performance: slight overhead
          - 記憶體容量: 需額外空間
          - 彈性高
          - 使用時機: 很多值，資料都有變動的可能性

      - 為甚麼要sorting? 二分法時，找特定的值很方便，time complexity會減少
        - 一般常見sort: Bubble、selection、merge、guiclc、bucket、insertion
        - sort 以記憶體分類為:
          - internal sort、external sort

      - Static Array優缺點、使用時機和time complexity
        - pros: 有random access(隨機存取)特性，每個元素都可以用o(1)時間存取 
        - cros: 在排序過的陣列中insert需要右移、delete需要左移，這些動態調整，時間複雜度為o(n)
        - 其中insert需要注意空間，delete需要做last()
        - 什麼時候適合用Static Array? 查找固定位置資料，但不適合頻繁更新資料的情境(這點跟linked list相反，存取慢但insert、delete快)

      -  Unsorted array v.s sorted array
        - Unsorted array
          - 全找完才會決定是否存在
          - linear search
          - o(n)
        - Sorted array
          - 不用全找，一定在某個特別位置
          - binary search
          - 因為sorted過，會較快速
           - o(logn)
- 9/30
  - linked list V.S array
    - 特性
      - array一開始就宣告陣列大小，而linked list是不動到data本身，利用**pointer**把data的連結位置改變，且存取初始值時須從haed起
    - 記憶體配置
      - array記憶體是連續的，linked list資料越來越大時會逐漸不連續，且每個節點都是動態的
    - 記憶體空間
      - array 沒有額外overhead
      - linked list 有額外overhead   
    
## array、linked time complexity   

| Table Size (m)               |             array        |      linked list               |
|------------------------------|--------------------------|--------------------------------|      
|  by index                    |            o(1)          |  o(n)(需要查找整個值)           |
|  insert                      |            o(n)          |  o(n)                          |
|  delete                      |            o(n)          |  o(n)                          |
|  by value                    |            o(n)          |  o(n)                          |
|  insert at front             |            o(n)          |  o(1)                          |
|  insert at middle            |            o(n)          |  o(n)                          |
|  insert at end               |            o(1)          |  o(n)/o(1)                     |
|  delete                      |            o(n)          |  o(n)/o(1)                     |
     
   - space
      - Linked list在空間利用上比較有效，需存資料的時候再create空間，在runtime時才決定
      -  Array必須先宣告預期空間，在random access較有效率
    -  performance
      - array 因為是連續memory，performance比較好
      - linked list performance較差，需要在memory間跳來跳去
    - 問題
      - 在實務中，因為Linked List雖然節點插入刪除方便，但在需要頻繁存取特定位置的排序演算法中並不理想;選擇 Array 版本的 Selection Sort 通常更有效率（隨機存取 O(1)）

- 10/7
  - linked list 型態
    - singly(都指向下一個位置)、doubly、circular
    - 通常singly複雜度>doubly、circular
  - linked list node exchange
    - 分為sorted 和 unsorted，隨著selection sort增加，sorted part越大，unsorted越小。 
    - step 1  sorted tail
    - step 2  min node
    - step 3  minprev(才知道下一個指向誰)(須注意相依性問題)
  - stable sort V.s unstable sort
    - eg: 4 5 10 2 11 2 (stable sort)
  - linked list by value 只有兩個變數(i、j)
  - linked list by pointer，需要考慮較多，程序複雜 

- 10/24
  - stack
    - 為先進後出(FILO)
    - 用top、push、pop
    - ADT:  stack create(mss)、boolean isFull(stack,mss)、boolean isEmpty(stack)、push(stack)、pop(stack)
    - stack可以分為用linked list和array做法。用array必須先create stackA和stackB，因為redo、undo不可能只用一個stack，用河內塔方式。
  - queue
    - 為先進先出(FIIFO) eg:排隊
    - 用front、rear、add、delete
    - ADT:  Queue CreateQ(j, list)、Boolean isFullQ(queue, mqs)、Boolean isEmptyQ(queue)、Queue AddQ(queue)、Queue DeleteQ(queue)

## 演算法        
### Stack 用 Linked List
- 優點：動態配置、省空間、無固定大小限制  
- 缺點：需考慮記憶體釋放 (`delete t`) 與指標管理問題  
- 時間複雜度：O(1)
```text
void push(Node *t)
{
    t->link = top;
    top = t;
}

bool pop(int &item)
{
    if (top == NULL)
        return false;
    Node *t = top;
    top = top->link;
    item = t->data;
    delete t;   // 釋放記憶體
    return true;
}
  ```
### Stack 用 array
- 缺點：要顧慮到top=-1、size=n-1，可能會有溢位問題
- 時間複雜度：O(1)
```text
      - bool push(int item)
      - {
      -   if( isFull() )
      -   return false;
      -   else
      -   {
      -   top = top+1;
      -   stack[top] = item;
      -   return true;
      -   }  
      - }
      - bool pop(int &item)
      - {
      -   if( isEmpty() )
      -   return false;
      -   else
      -   {
      -   item = stack[top];
      -   top = top-1;
      -   return true;
      -   }
      - }
  ```

### queue 用 linked list
- 缺點：因為有front、rear，有記憶體釋放ret(t)、指標管理問題
- 時間複雜度：O(1)

```text
  void add(Node *t)
  {
      if (rear == NULL)
          front = rear = t;
      else
      {
          rear->link = t;
          rear = t;
      }
  }

  bool Delete(int &item)
  {
      if (front == NULL)
          return false;
      else
      {
          Node *t = front;
          front = front->link;
          item = t->data;
          delete t;
          return true;
      }
  }
  ```

### queue 用 array
- 缺點：通常用circular array，必須考慮當(rear+1)%n==front時，newrear和front撞一起的問題。
- 時間複雜度：O(1)

```text
      - bool add(int item)
      - {
      -   int newrear = (rear+1)%n;
      -   if(newrear == front)
      -   return false;
      -   else
      -   {
      -   rear = nearear;
      -   CQ[rear] = item;
      -   return true;
      -   }  
      - }
      - bool delete(int &item)
      - {
      -   if(front==null)
      -   return false;
      -   else
      -   front = (front+1)%n;
      -   item  = CQ[front];
      -   return true;
      - }
  ```

- 12/1
## tree
- Def:tree 是一個非線性的data structure，有別於linked list，因為是hierarchical(有order)，所以沒有cycle
- <img width="1070" height="536" alt="image" src="https://github.com/user-attachments/assets/478c6645-36f7-4eff-ae1c-122f4d180978" />
- tree可採用linked list、括號法、left child-sibling方式轉成B.T
- tree的問題: 因為有太多null，太浪費space，故用B.T才能使浪費率降到(k-1)/k最小，省space


## binary tree(order tree)

               1
           /         \
         2            3
       /   \        /    \
      4     5      6      7
    
    input:  [1, 2, 3, 4, 5, 6, 7]

    in array:
    | Index | 0  | 1 | 2  | 3 | 4 | 5    | 6  |
    |-------|----|---|----|---|---|------|----|
    | Value | 1  | 2 | 3 | 4  | 5 | 6    | 7  |


- B.T型態: strict、complete(degree <=1 )、退化、prefect

## B.T前中後序、Count Node、高度、Leaf Node、B.T copy、equal、swap、expression tree 演算法

- B.T前序演算法
```text
  struct:
  class Node
    {
      Node *Lchild;
      int data;
      Node *Rchild;      
    }

    前序algo:
    void preorder( Node *T )
  {
    if( T != Null )
    {
      print( T->data );
      print( T->Lchild );
      print( T->Rchild );
    }
  }
    
```

- Count Node 演算法
```text
int count(Node *T)
{
    if (T == Null) return 0;
    else
    {
        int nL = count(T -> Lchild);
        int nR = count(T -> Rchild);
        return nL + nR + 1;
    }
}

```

- Leaf Node 演算法
```text

int countleaf(Node *T)
{
    if (T == Null) return 0;
    else
    {
        int nL = countleaf(T -> Lchild);
        int nR = countleaf(T -> Rchild);
        if ((nL + nR) == ∅) return 1;
        else return nL + nR;
    }
}

    
```



- B.T copy 演算法
```text

Node *copy(Node *orig)
{
    Node *d = new Node();
    if (orig != Null)
    {
        d -> data = orig -> data;
        d -> Lchild = copy(orig -> Lchild);
        d -> Rchild = copy(orig -> Rchild);
    }
    else d = null;
    return d;

}
    
```





- equal 演算法
```text
bool equal(Node *s, Node *t)
{
    bool x = false;  // case 2 結果為 x
    {
        if (s == Null && t == Null) return true;  // ①
        else if (s != Null && t != Null)  // ②
        {
            if (s->data == t->data)
            {
                if (equal(s->Lchild == t->Lchild))
                {
                    x = equal(s->Rchild == t->Rchild);
                }
            }
            return x;  // 只要 check 的過程不成立，即 return x = false
        }
        else return false;  // ③
    }
}
    
```




- swap 演算法
```text
void swap(Node *T)
{
    if (T != Null)
    {
        swap(T -> Lchild);
        swap(T -> Rchild);

        Node *tmp = T -> Lchild;
        T -> Lchild = T -> Rchild;
        T -> Rchild = tmp;
    }
}
    
```

- expression tree 演算法
```text

int Eval(Node *T)
{
    if (T != Null)
        Eval(T->Lchild);
        Eval(T->Rchild);
        switch(T->data)
        {
            case = 元運算子:
                T->result = count by T->data((T->Lchild)->Result, (T->Rchild)->Result);
            case = 元注算子:
                T->result = count by T->data((T->Rchild)->Result);
            case 常數 or 變數:
                T->result = 變數 or 常數;
        }
    return T->result;
}
    
```


## B.S.T


        1
         \
          2
           \    
            3
             \
              4
               \
                5
                 \
                  6
                   \
                    7
    
    input:  [10, 5, 15, 2, 7, 12, 20]

    in array:
    ## BST (array representation)

    | Index | Value |
    |-------|--------|
    | 1     | 1      |
    | 2     | NULL   |
    | 3     | 2      |
    | 4     | NULL   |
    | 5     | NULL   |
    | 6     | NULL   |
    | 7     | 3      |
    | 8–14  | NULL   |
    | 15    | 4      |
    | 16–30 | NULL   |  
    | 31    | 5      |
    | 32–62 | NULL   |
    | 63    | 6      |
    | 64–126 | NULL  |  
    | 127    | 7     |

    - 可以知道b.s.t用linked list較佳，因為可以靠pointer較不會浪費空間，產生很多null
    - 相對heap用array較佳  

## B.S.T、AVL Tree、Heap time complexity 

| Table Size (m)               |             beat case        |      worse case                |
|------------------------------|------------------------------|--------------------------------|      
|  B.S.T                       |            o(logn)           |  o(n)(斜曲樹時)                 |
|  AVL                         |            o(logn)           |  NO(解決不平衡，故無worse case)  |
|  haep                        |      insert = o(logn)        |  找最大值 = o(1)                |


# GRAPH
## Adjacency List: adjacency list：有 n 個頂點，有 n 條 linked list

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

|                        | adj matrix      | adj list        |
|------------------------|-----------------|-----------------|
| vertex 數              | ✗ O(n²)         | ✓               |
| edge 數                | ✓               | ✗               |
| check 邊是否存在       | ✓ O(1)          | ✗ O(e)          |
| 求總邊數               | ✗ O(n²)         | ✓ O(n + e)      |

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
