# Binary Expression Tree (運算式二元樹表示法)

概念:
- 使用 Binary Tree (B.T.) 來表示運算式（expression）
- 應用於 Compiler 剖析（Parsing），建立 Parsing Tree 或 Syntax Tree

原則:
1. Leaf 節點代表 Operand（運算元），Non-leaf 節點代表 Operator（運算子，如 +, -, *, /）
2. Operator 通常位於樹的高層（root 越近），其 Level 值較大（越下層）
3. 若以 Inorder traversal 走訪 B.T. 可得 Infix 表達式，但若要驗證正確性，需使用：
  - Postorder traversal 得到 Postfix 表達式
  - 或 Preorder traversal 得到 Prefix 表達式


## Binary Expression Tree的建構

```text
範例一:
表達式：a + b * c - d / e

則對應的 Binary Tree：

          -
         / \
        +   /
       / \ / \
      a  * d  e
        / \
       b   c


Traversal 結果：
Postorder：abc*+de/-
對應的 Infix：(a + (b * c) - (d / e))
兩者相等，表示樹構造正確


範例二:
表達式: (a + b) * c - d / (e * f) + g

則對應的 Binary Tree：

          +
       /     \
     -         g
   /   \
 *       /
/ \     / \
+  c   d   *
/ \         / \
a  b       e  f


```

## Expression Tree 演算法

```text

節點結構:
[ lchild | Data | Res | rchild ]

data 欄: 存operator 或 operand名稱
Res 欄: 存運算結果值或變數值
lchild：左子節點
rchild：右子節點

```

演算法:

```text

function Eval(T: Expression Binary Tree)
{
    if (T ≠ nil)
    {
        Eval(T → lchild);
        Eval(T → rchild);

        switch (T → Data)
        {
            case "+":
                T → Res = T → lchild → Res + T → rchild → Res;
                break;
            case "-":
                T → Res = T → lchild → Res - T → rchild → Res;
                break;
            case "*":
                T → Res = T → lchild → Res * T → rchild → Res;
                break;
            case "/":
                T → Res = T → lchild → Res / T → rchild → Res;
                break;
            case "~": // Unary operator
                T → Res = ~(T → rchild → Res);
                break;
            case "operand": // 變數名稱
                T → Res = operand 的值;
                break;
        }
    }
}



```
