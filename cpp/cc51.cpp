#include <bitset>
#include <iostream>

using namespace std;


int bitInsertion(int N, int M, int i, int j) {
    if (i>32 || j>32 || (j-i)<0) return N;
    int ret{N};
    int mask{j+1<32 ? (-1) << (j+1) : 0};
    mask |= ~((-1) << i);
    ret &= mask;
    ret |= (M << i);
    return ret;
}


void test() {
    int n = 178;  // 0b10110010
    int m = 6;    // 0b__0110__
    cout << bitset<8>(bitInsertion(n,m,2,5)) << endl;  // 0b10011010
}


int main() {
    test();
    return 0;
}
