#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "print.cpp"

using namespace std;


void carry(unordered_map<char, vector<string>> &phone,
           vector<int> &record, int digit, string &digits) {
    if (digit == 0) {
        record[digit]++;
    } else {
        record[digit]++;
        if (record[digit] >= int(phone[digits[digit]].size())) {
            record[digit] = 0;
            carry(phone, record, digit-1, digits);
        }
    }
}


vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits == "") return ret;
    unordered_map<char, vector<string>> phone{
        {'2', vector<string>{"a", "b", "c"}},
        {'3', vector<string>{"d", "e", "f"}},
        {'4', vector<string>{"g", "h", "i"}},
        {'5', vector<string>{"j", "k", "l"}},
        {'6', vector<string>{"m", "n", "o"}},
        {'7', vector<string>{"p", "q", "r", "s"}},
        {'8', vector<string>{"t", "u", "v"}},
        {'9', vector<string>{"w", "x", "y", "z"}},
    };
    int len = digits.size();
    vector<int> record (len, 0);
    while (record[0] < int(phone[digits[0]].size())) {
        string tmp;
        for (int i=0; i<len; ++i) {
            tmp += phone[digits[i]][record[i]];
        }
        ret.push_back(tmp);
        // printlnVector(record);
        carry(phone, record, len-1, digits);
    }
    return ret;
}


void test(vector<string> &t) {
    for (auto &i : t) {
        vector<string> ret{letterCombinations(i)};
        printlnVector(ret);
    }
}


int main() {
    vector<string> t{
        "23",
        "234"
    };
    test(t);
    return 0;
}
