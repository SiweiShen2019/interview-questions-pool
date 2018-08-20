#include <assert.h>
#include <iostream>
#include <string>
#include <vector>

#include "print.cpp"

using namespace std;


int findSmallest(vector<int> &digits) {
    int ret{digits[0]};
    for (int i=1; i<int(digits.size()); ++i) {
        if (digits[i] < ret) ret = digits[i];
    }
    return ret;
}


int findBigger(vector<int> &digits, int &src, int up) {
    int ret{10};
    for (auto &i : digits) {
        if (i<ret && i>src && i<=up) ret = i;
    }
    return ret;
}


string nextClosestTime(string &time) {
    vector<int> digits{
        time[0] - '0',
        time[1] - '0',
        time[3] - '0',
        time[4] - '0'
    };
    string ret{time};
    int smallest{findSmallest(digits)};
    // last digit
    int last_bigger{findBigger(digits, digits[3], 9)};
    if (last_bigger != 10) {
        return ret.replace(4, 1, to_string(last_bigger));
    }
    // second last
    int second_last_bigger{findBigger(digits, digits[2], 5)};
    if (second_last_bigger != 10) {
        ret = ret.replace(3, 1, to_string(second_last_bigger));
        return ret.replace(4, 1, to_string(smallest));
    }
    // second
    int second_bigger;
    if (digits[0] != 2) {
        second_bigger = findBigger(digits, digits[1], 9);  
    } else {
        second_bigger = findBigger(digits, digits[1], 3);
    }
    if (second_bigger != 10) {
        string tmp = to_string(digits[0]) + to_string(second_bigger);
        tmp += ":";
        tmp += to_string(smallest) + to_string(smallest);
        return tmp;
    } else {
        string tmp = to_string(smallest) + to_string(smallest);
        tmp += ":";
        tmp += to_string(smallest) + to_string(smallest);
        return tmp;
    }
    // first digit has been handled
    return "";
}


void test1() {
    string t{"19:34"};
    string e{"19:39"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


void test2() {
    string t{"14:29"};
    string e{"14:41"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


void test3() {
    string t{"14:59"};
    string e{"15:11"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}

void test4() {
    string t{"04:59"};
    string e{"05:00"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


void test5() {
    string t{"19:49"};
    string e{"11:11"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


void test6() {
    string t{"09:49"};
    string e{"00:00"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


void test7() {
    string t{"22:49"};
    string e{"22:22"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


void test8() {
    string t{"23:49"};
    string e{"22:22"};
    string r{nextClosestTime(t)};
    cout << r << endl;
    assert(e==r);
}


int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}