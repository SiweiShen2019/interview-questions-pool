#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "print.cpp"

using namespace std;


double calc(unordered_map<string, vector<pair<string, double>>> &data,
           string &start, string &end) {
    if (data.count(start) == 0) return -1.0;
    else if (data.count(end) == 0) return -1.0;
    else if (start == end) return 1.0;
    unordered_map<string, int> record;
    queue<pair<string, double>> visit;
    visit.push(make_pair(start, 1.0));
    while (!visit.empty()) {
        auto &curr = visit.front();
        auto &curr_str = get<0>(curr);
        auto &curr_weight = get<1>(curr);
        if (record.count(curr_str) == 0) {
            record[curr_str] = 1;
        } else {
            visit.pop();
            continue;
        }
        auto &neighbors = data[curr_str];
        for (auto &p : neighbors) {
            auto &neighbor = get<0>(p);
            auto &neighbor_weight = get<1>(p);
            double sofar_weight = curr_weight * neighbor_weight;
            // ignore self and recorded
            if (neighbor==start || record.count(neighbor)>0) continue;
            else if (neighbor == end) {
                return sofar_weight;
            } else {
                visit.push(make_pair(neighbor, sofar_weight));
            }
        }
        visit.pop();
    }
    return -1.0;
}


vector<double> calcEquation(vector<pair<string, string>> equations, 
                            vector<double>& values,
                            vector<pair<string, string>> queries) {
    unordered_map<string, vector<pair<string, double>>> data;
    int equation_length = equations.size();
    for (int i=0; i<equation_length; ++i) {
        auto &first = get<0>(equations[i]);
        auto &second = get<1>(equations[i]);
        auto &v = values[i];
        data[first].push_back(make_pair(second, v));
        data[second].push_back(make_pair(first, 1/v));
    }
    int queries_length = queries.size();
    vector<double> ret(queries_length, 0);
    for (int i=0; i<queries_length; ++i) {
        auto &first = get<0>(queries[i]);
        auto &second = get<1>(queries[i]);
        ret[i] = calc(data, first, second);
    }
    return ret;
}


void test0() {
    vector<pair<string, string>> equations{
        make_pair("a", "b"),
        make_pair("b", "c")
    };
    vector<double> values{2.0, 3.0};
    vector<pair<string, string>> queries{
        make_pair("a", "c"),
        make_pair("b", "a"),
        make_pair("a", "e"),
        make_pair("a", "a"),
        make_pair("x", "x"),
    };
    vector<double> ret{calcEquation(equations, values, queries)};
    printlnVector(ret);
}


int main() {
    test0();
    return 0;
}