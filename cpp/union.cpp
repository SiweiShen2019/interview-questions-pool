#include <assert.h>
#include <vector>

using namespace std;


class UF {
private:
    vector<int> id;
    vector<int> size;
    int components;


public:
    UF(int n) {
        components = n;
        id = vector<int>(n, 0);
        size = vector<int>(n, 0);
        for (int i=0; i<n; ++i) {
            id[i] = i;
            size[i] = 1;
        }
    }

    int count() {
        return components;
    }

    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];  // path compression
            p = id[p];
        }
        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    // union is a keyword in C++
    void merge(int p, int q) {
        int p_root = find(p);
        int q_root = find(q);
        if (size[p_root] < size[q_root]) {
            id[p_root] = q_root;
            size[q_root] += size[p_root];
        } else {
            id[q_root] = p_root;
            size[p_root] += size[q_root];
        }
        --components;
    }
};
