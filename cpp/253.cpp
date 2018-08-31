#include <algorithm>
#include <iostream>
#include <set>
#include <vector>


#include "print.cpp"

using namespace std;


class Interval {
public:
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


void printIntervalVector(vector<Interval> &intervals) {
    cout << "[";
    for (auto i=intervals.begin(); i!=intervals.end(); ++i) {
        if (i != intervals.begin()) cout << ",";
        cout << "(" << i->start << "," << i->end << ")";
    }
    cout << "]" << endl;
}


bool intervalComparison(Interval &a, Interval &b) {
    return a.start < b.start;
}


int minMeetingRooms(vector<Interval> &intervals) {
    int ret{0};
    multiset<int> starts;
    sort(intervals.begin(), intervals.end(), intervalComparison);
    for (auto &i : intervals) {
        while (!starts.empty() && i.start>=*starts.begin()) {
            starts.erase(*starts.begin());
        }
        starts.insert(i.end);
        ret = max(ret, (int)starts.size());
    }
    return ret;
}


void test() {
    vector<vector<Interval>> t{
        vector<Interval>{Interval(0,30), Interval(5,10), Interval(15,20)},
        vector<Interval>{Interval(7,10), Interval(2,4)},
        vector<Interval>{Interval(0,10), Interval(20,30), Interval(15,20)}
    };
    for (auto &i : t) {
        // printIntervalVector(i);
        int ret{minMeetingRooms(i)};
        cout << ret << endl;
    }
}


int main() {
    test();
    return 0;
}