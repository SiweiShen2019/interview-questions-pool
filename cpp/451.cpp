#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;


string frequencySort(string s) {
    unordered_map<char, int> char_map;
    priority_queue<pair<int, char>> char_queue;
    for (auto c : s) ++char_map[c];
    for (auto p : char_map) char_queue.push(make_pair(p.second, p.first));
    string ret = "";
    while (!char_queue.empty()) {
        auto &p = char_queue.top();
        ret.append(p.first, p.second);
        char_queue.pop();
    }
    return ret;
}


void test() {
    vector<string> tests{
        "tree",
        "cccaaa",
        "Aabb",
        "loveleetcode"
    };
    for (auto & s : tests) {
        string output = frequencySort(s);
        cout << "Input: " << s << " Output: " << output << endl; 
    }
}


int main() {
    test();
    return 0;
}
