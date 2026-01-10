# tree

Tree的定義:
- tree 是一個非線性的data structure，有別於linked list，因為是hierarchical(有order)，所以沒有cycle
- tree可採用linked list、括號法、left child-sibling方式轉成B.T
- tree的問題: 因為有太多null，太浪費space，故用B.T才能使浪費率降到(k-1)/k最小，省space
<img width="1070" height="536" alt="image" src="https://github.com/user-attachments/assets/478c6645-36f7-4eff-ae1c-122f4d180978" />

Reference: https://www.geeksforgeeks.org/dsa/tree-meaning-in-dsa/: https://www.geeksforgeeks.org/dsa/tree-meaning-in-dsa/

## Tree轉成Bianry Tree: Left-Child Right-Sibling Representation
(1)先定義節點結構：

<img width="532" height="114" alt="image" src="https://github.com/user-attachments/assets/23e149b6-ed03-45dc-806a-17c523d401ec" />

(2)依上述圖做轉化表示為：

<img width="525" height="335" alt="image" src="https://github.com/user-attachments/assets/193af5bb-657c-4ad2-b3f6-c1c0c3aec50c" />

(3)將兄弟點(同Level點)的分支線向右轉(順時針)轉45度

<img width="527" height="390" alt="image" src="https://github.com/user-attachments/assets/191b1e37-891b-42ef-9313-0dc5fca5341a" />

Reference: Fundamentals of Data Structures in C
