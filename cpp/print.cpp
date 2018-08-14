#include <iostream>
#include <vector>

using namespace std;


// print a vector like python
template <class T>
void printVector(vector<T> &v) {
    cout << "[";
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (i != v.begin()) cout << ", ";
        cout << *i;
    }
    cout << "]";
}


// wrap printVector and a new line
template <class T>
void printlnVector(vector<T> &v) {
    printVector(v);
    cout << endl;
}


// print a 2D vector like python
template <class T>
void printVOV(vector<vector<T>> &v) {
    cout << "[";
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (i != v.begin()) {
            cout << " ";  // align internal vectors
        }
        printVector(*i);
        if ((i+1) != v.end()) {
            cout << "," << endl;
        }
    }
    cout << "]" << endl;
}