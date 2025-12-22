# binary tree(order tree)

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
