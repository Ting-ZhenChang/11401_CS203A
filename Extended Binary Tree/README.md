# Extended Binary Tree (延伸二元樹)
- 定義: 
- 若一棵 Binary Tree 有 n 個節點，並以 linked list 表示，則會有 n+1 條 null links。
- 在這些 null links 上加入特殊節點，稱為 External Node（外部節點或失敗節點）。
- 其餘節點稱為 Internal Node（內部節點）。
- 此種 Binary Tree 稱為 Extended Binary Tree。
- 外部節點數 = 內部節點數 + 1
  - E = I+1

```text
Notes: 有些版本定義不同，External Node 當作 leaf（葉節點），Internal Node 當作 non-leaf（非葉節點）
```

## 路徑長度 Path Length

- 分為 Internal Path Length I 和 External Path Length E
  - Internal Path Length I：所有內部節點從 root 到該節點的路徑長度總和。
  - External Path Length E：所有外部節點從 root 到該節點的路徑長度總和。
 
## Internal Path Length 和 External Path Length 之關係

-  E = I + 2N (其中 N 為 Internal Node 數量)
-  E 和 I 成正比，若樹高越小，則 E 和 I 值越小，反之愈大
-  有一個Skewed Extended B.T，具有n個 internal nodes，求E值
