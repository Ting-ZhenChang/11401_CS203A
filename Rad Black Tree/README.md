# Red-Black Tree（紅黑樹）

紅黑樹性質與目的:
- 在和AVL Tree時間複雜度相同的情況下，紅黑數rotation的次數比較小
- 每個節點不是 紅色（R） 就是 黑色（B）
- Root 一定是黑色
- 所有外部節點皆為黑色
- 不能連續紅色

插入基本規則:
- 新插入的節點 一律為紅色（RED）
- 插入後若違反紅黑樹性質 → 需要 調整（Fix-up）
  - 調整方式包含：
    - Color Change（重新著色, C.C.）
    - Rotation（旋轉）：LL / RR / LR / RL


範例一:
插入順序: 4, 7, 12, 15, 3, 5, 14, 18
```text

(1) 插入 4
   樹為空 → 4 成為 root
   Root 必須是黑色

    4(B)

 (2) 插入 7
   7 為紅色，父節點 4 為黑色 → 合法

    4(B)
      \
       7(R)

 (3) 插入 12
   出現 RR case（右右）
   Uncle 為 NIL（黑） → Left Rotation + Recolor

     7(B)
     /   \
   4(R) 12(R)

 (4) 插入 15
   父節點 12 為紅，Uncle 4 為紅 → Color Change

      7(B)
     /   \
   4(B) 12(B)
            \
            15(R)

 (5) 插入 3、5
   插入後仍滿足性質（父為黑）

          7(B)
         /    \
      4(B)   12(B)
     /   \       \
   3(R) 5(R)     15(R)

(6) 插入 14
  出現 RL case（Right-Left）
  先 Right Rotation，再 Left Rotation

         7(B)
       /     \
    4(B)    14(B)
   /   \    /   \
 3(R) 5(R) 12(R) 15(R)

(7) 插入 18
  父 15 為紅，Uncle 12 為紅 → Color Change

        7(B)
       /     \
    4(B)    14(R)
   /   \    /   \
 3(R) 5(R) 12(B) 15(B)
                      \
                      18(R)

```
