# Thread Binary Tree(引線二元樹)
- 定義: 是一種利用 Binary Tree 中「原本為 NULL 的 child pointer」來指向 中序走訪（Inorder Traversal）下的前驅或後繼 的結構。
- Binary Tree 中：
  - 每個節點有 2 個 child pointers，若樹共有 n 個 nodes → 總 pointers = 2n
-  一棵樹實際使用的邊：
    -  edge 數 = n - 1
-  未使用（NULL）的 pointers 數：
    -  2n−(n−1)= n+1，這些 n+1 個空指標，threaded Binary Tree就可以利用。
-  概念: NULL child pointer 指向 中序前驅（predecessor）或 中序後繼（successor) 稱為引線。
-  優點:
    -  利用原本為空的 link
    -  容易找到中序前驅與後繼
    -  中序走訪不需 recursion 和 序走訪不需 stack，易簡化中序追蹤
- 節點結構:
  -  | lthread | lchild | data | rchild | rthread |

```text

lchild: 左子節點指標
rchild	右子節點指標
lthread	true：左指標為 thread
lthread false：左指標為 child
rthread	true：右指標為 thread
rthread false：右指標為 child

其中，lthread / rthread 的意義:
  false → 指向真正的 child
  true  → 指向 inorder predecessor / successor

```
## 為什麼可以省掉 Stack / Recursion？

- 傳統 Inorder Traversal：
  - 需要 stack 或 recursion
- Threaded Binary Tree：
  - 可直接透過 thread，一步一步找到下一個節點


```text

範例一: Binary Tree

        A
       / \
      B   C
     / \ / \
    D  E F  G

Inorder Traversal: D B E A F C G

D 的 predecessor：NULL
D 的 successor：B
E 的 successor：A
F 的 predecessor：A
G 的 successor：NULL
（實際上會用 thread 指向這些節點）

```
流程圖:

![28843](https://github.com/user-attachments/assets/a49617aa-f55e-4992-85e0-03dca8fee576)


```text

範例二: Inorder Successor / Predecessor

原始 Binary Tree:

    A
   / \
  B   D
   \
    C


用Threaded Binary Tree表示?

中序: B C A D

```

流程圖:

![62737](https://github.com/user-attachments/assets/244b95bf-c63d-4060-9b30-a2e88476da5f)


## Thread Binary Tree 演算法

想法: 給定節點 X，找它的 inorder successor
- 如果 X 沒有右子樹:
  - rthread == true
  - X->rchild 直接就是後繼
- 如果 X 有右子樹:
  - rthread == false
  - 到 右子樹中「最左邊」的節點
 
 ```text

Node* insucc(Node* x)
{
    Node* tmp = x->rchild;        

    if (x->rthread == false)       
    {
        while (tmp->lthread == false)
        {
            tmp = tmp->lchild;    
        }
    }

    return tmp;
}

```

想法: 給定節點 X，找它的 inorder predecessor
- 如果 X 沒有左子樹:
  - lthread == true
  - X -> lchild 直接就是前驅
- 如果 X 有左子樹:
  - lthread == false
  - 到 左子樹中「最右邊」的節點
 
 ```text

Node* inpred(Node* x)
{
    Node* tmp = x->lchild;

    if (x->lthread == false)        
    {
        while (tmp->rthread == false)
        {
            tmp = tmp->rchild;      
        }
    }

    return tmp;
}


```
