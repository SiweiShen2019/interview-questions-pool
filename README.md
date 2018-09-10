# Interview Questions Pool

## Tools
### C++ Makefile
My source codes and C++ Makefile are put in [`cpp/`](cpp). cpp files are named after their number in [LeetCode](https://leetcode.com/). You can modify and use my [Makefile](cpp/Makefile) and run cpp files like python.

Say that you write some codes for question 123:

- Compile `123.cpp` into an executable file `123`(Unix-based System):
    ```
    make no=123
    ./123
    ```
- [**Pythonic**] Compile and run `123.cpp` (the executable file will be removed after being executed):
    ```
    make run no=123
    ```
- Clean `.o` files:
    ```
    make clean
    ```

### C++ Libs
In order to leverage the process of debugging, I write [`print.cpp`](cpp/print.cpp) to print vectors like I used to do in python. However, it's just a very tough implementation, so only `int` and `string` are supported to be elements in a vector.

Examples:

- Print a vector:
    ```cpp
    vector<int> v{1,2,3};
    printVector(v);
    ```
    ```
    [1,2,3]
    ```

- Print a vector of vectors of ints:
    ```cpp
    vector<vector<int>> v{{1,2}, {3,4}, {5,6}};
    printVOV(v);
    ```
    ```
    [[1, 2],
     [3, 4],
     [5, 6]]
    ```

## Index
By default:
- "Notes" use C++ codes to explain my thoughts.
- Python and Go codes are implemented following C++ codes. However,
    - If a question is difficult, I may write a Python script first.
    - It's a good place to learn the grammar of other languages.
    - I may add other languages later on.

### LeetCode
|Questions|C++|Python|Go|Notes|
|--|--|--|--|--|
|[451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)|[451.cpp](cpp/451.cpp)|||[451](notes/451.md)|
|[138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)|[138.cpp](cpp/138.cpp)||||
|[253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)|[253.cpp](cpp/253.cpp)||||
|[17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)|[17.cpp](cpp/17.cpp)||||
|[283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)|[283.cpp](cpp/283.cpp)|||[283](notes/283.md)|
|[399. Evaluate Division](https://leetcode.com/problems/evaluate-division/)|[399.cpp](cpp/399.cpp)||||
|[113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)|[113.cpp](cpp/113.cpp)|||[113](notes/113.md)|
|[566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/)|[566.cpp](cpp/566.cpp)||[566.go](go/566.go)|[566](notes/566.md)|
|[404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)|[404.cpp](cpp/404.cpp)|||[]()|
|[655. Print Binary Tree](https://leetcode.com/problems/print-binary-tree/)|[655.cpp](cpp/655.cpp)|||[655](notes/655.md)|

### Cracking the Coding Interview
|Questions|C++|Notes|
|--|--|--|
|[5.1 Insertion (LintCode 179)](https://www.lintcode.com/problem/update-bits/)|[cc51.cpp](cpp/cc51.cpp)||


## Reference
[Jason Turner's C++ Coding Standards](https://gist.github.com/lefticus/10191322)  
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)  