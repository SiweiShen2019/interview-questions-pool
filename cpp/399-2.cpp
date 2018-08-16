#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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
        auto &neighbors = data[curr_str];
        for (auto &p : neighbors) {
            auto &neighbor = get<0>(p);
            auto &neighbor_weight = get<1>(p);
            double sofar_weight = curr_weight * neighbor_weight;
            if (neighbor == start) continue;  // igonre self
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
    for (auto i=equations.begin(); i!=equations.end(); ++i) {
        auto j = values.begin();
        auto &first = get<0>(*i);
        auto &second = get<1>(*i);
        auto &v = (*j);
        data[first].push_back(make_pair(second, v));
        data[second].push_back(make_pair(first, 1/v));
        ++j;  // due to the same size, no need to check j
    }

}