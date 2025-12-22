# B.S.T

特性: 
  - 若任意節點的左子樹不空，則左子樹上所有節點的值均小於它的根節點的值
  - 若任意節點的右子樹不空，則右子樹上所有節點的值均大於它的根節點的值
  - 任意節點的左、右子樹也分別為二元搜尋樹

<img width="720" height="427" alt="image" src="https://github.com/user-attachments/assets/3cfdba6c-4410-4d01-8379-850156fe517c" />

    worse case為skewed tree:
    
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
    
    - B.S.T用linked list較佳，因為可以靠pointer較不會浪費空間，產生很多null
    - 相對HAEP用array較佳 
    
    假設input:  [10, 5, 15, 2, 7, 12, 20]    
    BST (array representation):

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

## Delete（刪除）節點規則
- 情況 1：Leaf Node（無 child）: 直接刪除
- 情況 2：只有一個 child: 用 child 取代該節點
- 情況 3：有兩個 child
  
  兩種常見做法（擇一）：
    - 用 左子樹的最大值 取代
    - 用 右子樹的最小值 取代


BST 範例一

         60
         /  \
       50    70
      /  \     \
    40   55     80
      \          \
      48         100

❌ 不是 BST
原因：48 < 50，卻出現在 50 的 右子樹

BST 範例二（Insertion）

插入順序: 26, 5, 77, 8, 19, 31, 17, 45

        26
       /  \
      5    77
       \
        8
         \
         19
        /  \
      17   31
              \
               45

## Traversal 與 BST 特性
- BST 的 Inorder Traversal 會得到「排序後結果」

Inorder：A B C D F K L P
Postorder： A B F K P L D

因此，由中序+後序得到:
  
        D
       / \
      B   L
     / \   \
    A   C   P
           /
          K
         /
        F
        
所以，Preorder結果: D B A C L K F P

- B.S.T 演算法
```text
bool search(Node *T, int x)
{
    if (T == NULL) return false;
    else
    {
        if (T->data == x) return true;
        else if (x < T->data) return search(T->Lchild, x);
        else return search(T->Rchild, x);
    }
}
```

## BST 操作與時間複雜度
| Operation | 說明                         | Best Case | Worst Case |
|-----------|------------------------------|-----------|------------|
| Insert    | 依 BST 規則由 root 往下插入 | O(log n)  | O(n)       |
| Delete    | 依節點子樹情況刪除           | O(log n)  | O(n)       |
| Search    | 由 root 開始比較搜尋         | O(log n)  | O(n)       |

⚠️ Worst case 通常發生在 BST 退化成鏈狀（像 Linked List） 時。
