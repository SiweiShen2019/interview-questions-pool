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
In order to leverage the process of debugging, I write [`print.cpp`](cpp/print.cpp) to print vectors like I used to do in python. However, it's just a very rough implementation, so only `int` and `string` are supported to be elements in a vector.

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


## Catch2
[A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD - using C++11, C++14, C++17 and later (or C++03 on the Catch1.x branch)](https://github.com/catchorg/Catch2)


## Index
By default:
- "Notes" use C++ codes to explain my thoughts.
- Python, Java, and Go codes are implemented following C++ codes. However,
    - If a question is difficult, I may write a Python script first.
    - It's a good place to learn the grammar of other languages.
    - I may add other languages later on.


### LeetCode
#### Array
|Questions|C++|Java|Python|Go|Notes|
|--|--|--|--|--|--|
|[26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)|[26.cpp](cpp/26.cpp)|[lc26.java](java/lc26.java)|||Two pointers|
|[41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/)|[41.cpp](cpp/41.cpp)||||Array as one-to-one map (Hint 1)|
|[*80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)|[80.cpp](cpp/80.cpp)||||One pointer. [Best Solution](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby)|


## Reference
[Jason Turner's C++ Coding Standards](https://gist.github.com/lefticus/10191322)  
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
