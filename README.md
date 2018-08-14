# leetcode-solutions

## Tools
### C++ Makefile
My source codes and C++ Makefile are put in [`cpp/`](cpp). cpp files are named after their number in [LeetCode](https://leetcode.com/). You can modify and use my [Makefile ](cpp/Makefile) and run cpp files like python.

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

## Index
By default:
- "Notes" use C++ codes to explain my thoughts.
- Python and Go codes are implemented following C++ codes. However,
    - If a question is difficult, I may write a Python script first.
    - It's a good place to learn the grammar of other languages.
    - I may add other languages later on.


|Questions|C++|Python|Go|Notes|
|--|--|--|--|--|
|[404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/)|[404.cpp](cpp/404.cpp)|||[]()|
|[566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/description/)|[566.cpp](cpp/566.coo)|||[566](notes/566.md)|
|[655. Print Binary Tree](https://leetcode.com/problems/print-binary-tree/description/)|[655.cpp](cpp/655.cpp)|||[655](notes/655.md)|


## Reference
[Jason Turner's C++ Coding Standards](https://gist.github.com/lefticus/10191322)  
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)  