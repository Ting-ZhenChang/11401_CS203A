 - 尋找最佳路徑 eg: google map
    - vertex(node)、edge(link/line)
      
  - Array 
    - Array是連續記憶體空間(contiguous memory locations)，time complexity: o(1)
   
       ```text
       - size of array分為: 靜態和動態

      靜態: 在編譯時陣列大小就決定了，是不能被改變的，存取快速但彈性差
      動態
        └── malloc / realloc 可能失敗在 C 裡，malloc 或 realloc 失敗時會回傳 NULL。你的程式沒有檢查回傳值，若失敗直接使用會 segmentation fault
          └── %p表示print pointer， 需搭配void*，\n表換行
            └── malloc / realloc 可能失敗在 C 裡，malloc 或 realloc 失敗時會回傳 NULL。你的程式沒有檢查回傳值，若失敗直接使用會 segmentation fault
                └── stack: 是一個指標指向heap記憶體，不能隨便擴充且會保留原值
                   └── heap: 用malloc/new要來的動態記憶體，可用free釋放。一般都會在heap區塊後擴充，但如果heap不夠，系統會在heap找一塊更大的空間，把舊資料copy上去，並釋放舊的空間
       size會在runtime時跟系統要一個空間，使用malloc、realloc時，須注意需要自己管理記憶體，最後必須free掉，否則造成效率低或記憶體外洩

       ```

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

## linked list 和 array sorting 的比較
  - 為何要做sorting? search時，找特定的值很方便，time complexity會減少
  - 一般常見sort: Bubble、selection、merge、guiclc、bucket、insertion
  - sort 以記憶體分類為: internal sort、external sort
  - 類似概念: binary search tree、Hash open address

| 結構        | 搜尋型態            | 時間複雜度 | sorting 優勢                                      | sorting 劣勢                                | 情境                                         | 空間利用率                                                   | performance                                |
|-------------|---------------------|------------|---------------------------------------------------|---------------------------------------------|----------------------------------------------|--------------------------------------------------------------|--------------------------------------------|
| linked list | sequential search   | O(n)       | 在已知位置下 insert、delete 快，O(1)              | link traversal issue                         | insert、delete 快，適合頻繁更新資料的情境    | 比較有效，需存資料時再 create 空間，runtime 時才決定          | performance 較差，需要在 memory 間跳來跳去 |
| array       | random access       | O(1)       | 有 random access 特性，每個元素都可 O(1) 時間存取 | 在排序陣列中 insert 需右移、delete 需左移，時間複雜度 O(n) | 查找固定位置資料，但不適合頻繁更新資料的情境 | 較無效，必須先宣告預期空間                                   | 連續 memory，performance 較好              |
      
      
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

  - 問題: 在實務中，因為Linked List雖然節點插入刪除方便，但在需要頻繁存取特定位置的排序演算法中並不理想;選擇 Array 版本的 Selection Sort 通常更有效率（隨機存取 O(1)）
    
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
