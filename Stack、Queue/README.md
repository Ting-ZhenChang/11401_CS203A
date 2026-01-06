# Stack
  - 為先進後出(FILO)
  - 用top、push、pop
  - ADT:
    - stack create(mss)
    - boolean isFull(stack,mss)
    - boolean isEmpty(stack)
    - push(stack)
    - pop(stack)
  - stack可以分為用linked list和array做法。用array必須先create stackA和stackB，因為redo、undo不可能只用一個stack，用河內塔方式。

<img width="1164" height="594" alt="image" src="https://github.com/user-attachments/assets/4aaccb26-6df7-487c-a1c1-5ca1196f3e56" />



# Queue
  - 為先進先出(FIIFO) eg:排隊
  - 用front、rear、add、delete
  - ADT:
    - Queue CreateQ(j, list)、
    - Boolean isFullQ(queue, mqs)
    - Boolean isEmptyQ(queue)
    - Queue AddQ(queue)
    - Queue DeleteQ(queue)
- 種類:
  - 一般queue
  - priority Queue
  - double-ended Queue: 前端尾端都可插入和刪除
  - double-ended priority Queue: 為高等樹的MinMax Heap/Deep/SMMH 使用  

   
<img width="1276" height="494" alt="image" src="https://github.com/user-attachments/assets/fce9c4f3-adb3-46f6-9b98-abdcc55dbef5" />


## Stack、Queue應用

| 結構 | Stack | Queue |
|----|----|----|
|| 遞迴 (Recursion)、函式呼叫、- Infix → Postfix / Prefix 轉換、後序式計算、Compiler 文法剖析、括號檢查、取餐盤 (模擬 LIFO)、Input data 反序、Binary Tree 前序 / 中序 / 後序走訪、DFS (深度優先搜尋)、Stack-based computer instructions (zero-operated)、八皇后問題、西洋棋模擬 (皆為 LIFO) | 作業排程 (Job scheduling)、裝置佇列 (Device queue)、效能模擬 / 系統壓力測試、輸入輸出緩衝區 (I/O buffer)、BFS、Priority Queue (FIFO + Heap)、排隊、Binary Tree 的 Level Order Traversal |



## Stack 用 Linked List演算法        
- 優點：動態配置、省空間、無固定大小限制  
- 缺點：需考慮記憶體釋放 (`delete t`) 與指標管理問題  
- 時間複雜度：O(1)
  
```text
class Node {
public:
    int data;
    Node* link;
};

Node* top = nullptr;

void create() {
    top = nullptr;
}

void push(Node* A) {
    A->link = top;
    top = A;
}

bool pop(int &item) {
    if (top == nullptr) return false;
    Node* temp = top;
    top = top->link;
    item = temp->data;
    delete temp;
    return true;
}
  ```

圖示:

<img width="562" height="1254" alt="image" src="https://github.com/user-attachments/assets/c08dbd1a-6dfd-4785-9ea3-776d4906cd15" />



## Stack 用 array 演算法
- 缺點：要顧慮到top=-1、size=n-1，可能會有溢位問題
- 時間複雜度：O(1)
```text
     struct Stack {
    int* stack;
    int top;
    int n; // size
};

void create(int size) {
    top = -1;
    n = size;
    stack = new int[n];
}

bool isEmpty() { return top == -1; }
bool isFull() { return top == n - 1; }

bool push(int item) {
    if (isFull()) return false;
    else {
      stack[++top] = item;
      return true;
    }
}

int pop() {
    if (isEmpty()) return -1;
    else{
      return stack[top--];
    }
}
  ```

圖示:

<img width="346" height="441" alt="螢幕擷取畫面 2026-01-06 194202" src="https://github.com/user-attachments/assets/ed04ae64-b53c-440c-915e-8b6578338bcd" />



## queue 用 Single linked list 演算法
- 缺點：因為有front、rear，有記憶體釋放ret(t)、指標管理問題
- 時間複雜度：O(1)

```text

  class Node {
public:
    int data;
    Node* link;
};

Node* rear = nullptr;

// 插入 (Add)
void add(Node* t) {
    if (rear == nullptr) {
        rear = t;
        rear->link = t; // 指向自己形成環
    } else {
        t->link = rear->link;
        rear->link = t;
        rear = t;
    }
}

bool del(int &item) {
    if (rear == nullptr) return false;
    else{
      Node* t = rear->link;       // front = rear->link
      rear->link = t->link;
      item = t->data;
      if (rear == t) rear = nullptr; // 只有一個節點時刪除後清空
      delete t;
      return true;
      }
}

  ```

圖示:

<img width="628" height="994" alt="image" src="https://github.com/user-attachments/assets/cecc5eb9-5fee-42f5-bbdc-252465b2f7c5" />


## queue 用 circular linked list 演算法

```text

class Node {
public:
    int data;
    Node* link;
};

Node* front = nullptr;
Node* rear = nullptr;

// 建立
void create() {
    front = rear = nullptr;
}

// 插入 (尾端)
void add(Node* t) {
    if (rear == nullptr) {
        front = rear = t;
    } else {
        rear->link = t;
        rear = t;
    }
}

// 刪除 (前端)
bool del(int &item) {
    if (front == nullptr) return false;
    else{
      Node* t = front;
      front = front->link;
      item = t->data;
      delete t;
      if (front == nullptr) rear = nullptr;
      ret(t);
      return true;
    }
}

  ```
圖示:

<img width="640" height="344" alt="image" src="https://github.com/user-attachments/assets/425b77eb-fbb3-4c05-bd96-4f2da61a5ae2" />
<img width="586" height="442" alt="image" src="https://github.com/user-attachments/assets/010bc946-d8fb-4569-b99d-d7c90f019dc6" />
<img width="510" height="370" alt="image" src="https://github.com/user-attachments/assets/a5ce4b2a-5b27-46fe-93c9-b595141820a1" />


## queue 用 liner array 演算法

queue用array可以分為liner array 和 circular array。
- liner array 缺點:
  - 當 rear == n 時不一定滿，可能需要左移元素
  - 時間複雜度: o(n)
- circular array缺點：
  - 通常用circular array，必須考慮當(rear+1)%n==front時，newrear和front撞一起的問題。
  - 時間複雜度：O(1)

```text
      struct Queue {
    int* queue;
    int front, rear, n;
};

// 建立
void create(int size) {
    front = rear = -1;
    n = size;
    queue = new int[n];
}

// 判斷滿
bool isFull() { return rear == n - 1; }

// 判斷空
bool isEmpty() { return front == rear; }

// 插入 (尾端)
bool add(int item) {
    if (isFull()) return false;
    rear++;
    queue[rear] = item;
    return true;
}

// 刪除 (前端)
bool del(int &item) {
    if (isEmpty()) return false;
    front++;
    item = queue[front];
    return true;
}
  ```
圖示:

<img width="386" height="342" alt="image" src="https://github.com/user-attachments/assets/664ad6be-97e3-4158-945b-6e03abc6fb35" />

<img width="364" height="370" alt="image" src="https://github.com/user-attachments/assets/5261ca07-93e2-41bf-b3fd-2f6aed85bb0d" />


## queue 用 circular array 演算法

```text


struct Queue {
    int* ca;
    int front, rear, n;
};

// 建立
void create(int size) {
    front = rear = 0;
    n = size;
    ca = new int[n];
}

// 插入 (尾端)
bool add(int item) {
    int newRear = (rear + 1) % n;
    if (newRear == front) return false; // 滿
    rear = newRear;
    ca[rear] = item;
    return true;
}

// 刪除 (前端)
bool del(int &item) {
    if (front == rear) return false; // 空
    front = (front + 1) % n;
    item = ca[front];
    return true;
}

```
圖示:

<img width="854" height="848" alt="image" src="https://github.com/user-attachments/assets/f5f9772e-e5bf-4735-8155-20434c3df4b6" />

<img width="768" height="740" alt="image" src="https://github.com/user-attachments/assets/7b1b350b-24e0-4b68-9b90-db909a6fbf0a" />



## 為甚麼liner array 不適合用 Queue ? 
因為當rear == n 時不見得空間滿了，可能front > 0，所以需要將元素左移，但會用到迴圈時間複雜度會從o(1)到o(n)，故還是用circular array較佳。


# 補充: Stack 與 Queue 的互相模擬
## 用 stack 做成 Queue

<img width="594" height="1002" alt="image" src="https://github.com/user-attachments/assets/fc4264f8-35dd-49ff-9dd8-0411ce4d56bf" />

## 用 Queue 做成 Stack 

<img width="822" height="888" alt="image" src="https://github.com/user-attachments/assets/021060eb-c986-4ed0-a1d2-c67b0ffd95ce" />
