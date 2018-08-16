#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#include "print.cpp"
#include "union.cpp"

using namespace std;


vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    // iterate pairs and build maps
    int count{0};
    int pos{0};
    unordered_map<string, int> sti;
    unordered_map<int, int> record;  // <val in UF, pos in equ>
    for (auto &p : equations) {
        auto &first = get<0>(p);
        auto &second = get<1>(p);
        if (sti.count(first) == 0) {
            sti[first] = count;
            record[count] = pos;
            ++count;
        }
        if (sti.count(second) == 0) {
            sti[second] = count;
            record[count] = pos;
            ++count;
        }
        ++pos;
    }
    UF data{count};
    unordered_map<string, int> val_map;
    for (int i=0; i<equations.size(); ++i) {
        
    }
}