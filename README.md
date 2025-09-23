<img width="378" height="81" alt="image" src="https://github.com/user-attachments/assets/edb5cb01-0cc5-42ba-a64b-dca628316718" /><img width="688" height="210" alt="image" src="https://github.com/user-attachments/assets/c56f4046-81b2-4320-97c9-f3156e5c3f18" /># 11401_CS203A
- **姓名:** 張婷媜
- **學號:** 1112463
## 課程資訊
- **課程名稱:** 資料結構
- **授課教師:** 黃鈺峰老師
- **課號:** CS203A
- **學分數:** 3
- **學期長度:** 18周 
- **上課時間:**
  - 禮拜一 9:10-10:00
  - 禮拜二 15:10~17:00
## 課程描述 
- 本課程讓我們了解什麼是資料結構，它跟演算法之間的關係，以及會如何去影響到記憶體。課程內容包含linked lists, stacks, graphs, hashing, arrays等主題，理解和掌握資料結構的基本操作，學習到問題解決的能力。
## 課程筆記
- 9/9
  - C 的資料結構 = 記憶體操作，資料結構主在於讓記憶體空間最小化。因為工程師需要自己負責記憶體配置和釋放，雖然效率高、可預測性強，但需要自行管理，若錯誤會造成記憶體洩漏或程式崩潰。
  - 程式的資料都必須存放在記憶體中才能被處理。記憶體包含:Variables、Data structures、Temporary buffers，資料越動態、越複雜 → 記憶體管理的重要性越高。
  - 指標是儲存變數或物件的記憶體位址，協助記住每一筆資料放在哪裡。指標讓程式設計師直接操作記憶體 → 強大但危險，需要小心避免 memory leak & crash
  - 效能考量：記憶體區塊的擺放方式會影響快取與存取效率
  - 學習價值：打好基礎，能進行低階除錯與安全的記憶體操作
  - 5H1W
    - What
      - 用什麼形式去保存與組織，讓data更有效率
    - Why
      - 取資料有效率，不同資料結構取決於不同演算法，用最少最短的記憶體時間
    - When
      - 快速查找可以用hash、tree可以用大型資料庫儲存、queue可以讓cpu分時處理達到多功能
    - Where
      - os、AL&ML、database
    - Who
      - 學生、軟體工程師、研究演算法的人
    - How
      - 學會挑選合適的資料結構和演算法，在多人使用下，用好的演算法來加速運算和管理。查詢、insert、delete、update都有不同資料結構
  - Jave為了解決machine code問題(不相容)，會用bytecode經過vm，再轉成Machine code
    
- 9/15
  - 尋找最佳路徑 eg: google map
    - vertex(node)、edge(link/line)
      
- 9/28
  - Array 
    - Array是連續記憶體空間(contiguous memory locations)，time complexity: o(1)

    - size of array分為: 靜態和動態
      - 靜態: 在編譯時陣列大小就決定了，是不能被改變的，存取快速但彈性差
      - 動態: size會在runtime時跟系統要一個空間，使用malloc、realloc時，須注意需要自己管理記憶體，最後必須free掉，否則造成效率低或記憶體外洩

    - Dynamic Array需要知道:
      - malloc / realloc 可能失敗在 C 裡，malloc 或 realloc 失敗時會回傳 NULL。你的程式沒有檢查回傳值，若失敗直接使用會 segmentation fault
      - %p表示print pointer， 需搭配void*，\n表換行
      - stack: 是一個指標指向heap記憶體，不能隨便擴充且會保留原值
      - heap: 用malloc/new要來的動態記憶體，可用free釋放。一般都會在heap區塊後擴充，但如果heap不夠，系統會在heap找一塊更大的空間，把舊資料copy上去，並釋放舊的空間

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

      - 為甚麼要sorting? 二分法時，找特定的值很方便，time complexity會減少
        - 一般常見sort: Bubble、selection、merge、guiclc、bucket、insertion
        - sort 以記憶體分類為:
          - internal sort、external sort

      - Static Array優缺點、使用時機和time complexity
        - pros: 有random access(隨機存取)特性，每個元素都可以用o(1)時間存取 
        - cros: 在排序過的陣列中insert需要右移、delete需要左移，這些動態調整，時間複雜度為o(n)
        - 其中insert需要注意空間，delete需要做last()
        - 什麼時候適合用Static Array? 查找固定位置資料，但不適合頻繁更新資料的情境(這點跟linked list相反，存取慢但insert、delete快)

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
