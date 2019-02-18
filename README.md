# Interview Questions Pool

## Index


### LeetCode
#### Array
|Questions|C++|Java|Python|Go|Notes|
|--|--|--|--|--|--|
|[26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)|[26.cpp](cpp/26.cpp)|[lc26.java](java/lc26.java)|||Two pointers|
|[41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/)|[41.cpp](cpp/41.cpp)||||Array as one-to-one map (Hint 1)|
|[55. Jump Game](https://leetcode.com/problems/jump-game/)|[55.cpp](cpp/55.cpp)||||DP. [Best Solution](https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B)|
|[*80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)|[80.cpp](cpp/80.cpp)||||One pointer. [Best Solution](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby)|
|[134. Gas Station](https://leetcode.com/problems/gas-station/)|[134.cpp](cpp/134.cpp)||||Math proof. [Best Solution](https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.)|
|[189. Rotate Array](https://leetcode.com/problems/rotate-array/)|[189.cpp](cpp/189.cpp)||||`reverse` 3 times|


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


## Reference
[Jason Turner's C++ Coding Standards](https://gist.github.com/lefticus/10191322)  
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
