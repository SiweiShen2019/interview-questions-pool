#include <iostream>
#include <vector>

#include "print.cpp"

using namespace std;


vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
    if (nums.empty() || nums[0].empty()) return nums;
    int rr = nums.size();
    int cc = nums[0].size();
    if (rr*cc != r*c) return nums;
    vector<vector<int>> ret(r, vector<int>(c, 0));
    for (int i=0; i<rr; ++i) {
        for (int j=0; j<cc; ++j) {
            int index{i*cc + j};
            ret[index/c][index%c] = nums[i][j];
        }
    }
    return ret;
}


void testPrint() {
    vector<vector<int>> v{{1,2}, {3,4}, {5,6}};
    printVOV(v);
}


void test1() {
    vector<vector<int>> v{{1,2}, {3,4}, {5,6}};
    printVOV(v);
    vector<vector<int>> ret = matrixReshape(v, 2, 3);
    printVOV(ret);
}


void test2() {
    vector<vector<int>> v{{1,2}, {3,4}};
    printVOV(v);
    vector<vector<int>> ret = matrixReshape(v, 2, 4);
    printVOV(ret);
}

int main() {
    // testPrint();
    test1();
    test2();
    return 0;
}
