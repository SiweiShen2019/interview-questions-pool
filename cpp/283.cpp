#include <algorithm>
#include <iostream>
#include <vector>

#include "print.cpp"

using namespace std;


void moveZeroes(vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) return;
    int zero{0};
    for (int nonzero{0}; nonzero<len; ++nonzero) {
        if (nums[nonzero] != 0) {
            swap(nums[nonzero], nums[zero++]);
        }
    }
}


void test(vector<vector<int>> &v) {
    cout << "--------" << endl;
    for (auto &t : v) {
        cout << "before: ";
        printlnVector(t);
        moveZeroes(t);
        cout << "after: ";
        printlnVector(t);
        cout << "--------" << endl;
    }
}


int main() {
    vector<vector<int>> v{
        vector<int>{0,1,0,3,12},
        vector<int>{0,1,0,2,0,3},
        vector<int>{0,0,0,1,3,0},
        vector<int>{1,2,3,0,0}
    };
    test(v);
    return 0;
}
