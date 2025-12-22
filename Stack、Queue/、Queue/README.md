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
