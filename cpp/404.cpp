#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isLeaf(TreeNode &node) {
    return !node.left && !node.right;
}


int sumOfLeftLeaves(TreeNode *root) {
    if (!root) return 0;
    int sum{0};
    vector <TreeNode *> node_queue{root};
    while (!node_queue.empty()) {
        auto curr = *node_queue.begin();
        auto left = curr->left;
        auto right = curr->right;
        if (left) {
            node_queue.push_back(left);
            if (isLeaf(*left)) sum += left->val;
        } 
        if (right) node_queue.push_back(right);
        node_queue.erase(node_queue.begin());
    }
    return sum;
}


void testRoot() {
    TreeNode t1 = TreeNode(1);
    cout << sumOfLeftLeaves(&t1) << endl;
}


void testZero() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    t1.right = &t2;
    cout << sumOfLeftLeaves(&t1) << endl;
}


void test1() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    t1.left = &t2;
    t1.right = &t3;
    cout << sumOfLeftLeaves(&t1) << endl;
}


void test2() {
    TreeNode t1 = TreeNode(3);
    TreeNode t2 = TreeNode(9);
    TreeNode t3 = TreeNode(20);
    TreeNode t4 = TreeNode(15);
    TreeNode t5 = TreeNode(7);
    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;
    cout << sumOfLeftLeaves(&t1) << endl;
}


void test3() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    TreeNode t4 = TreeNode(4);
    TreeNode t5 = TreeNode(5);
    TreeNode t6 = TreeNode(6);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t3.left = &t5;
    t5.left = &t6;
    cout << sumOfLeftLeaves(&t1) << endl;
}


int main() {
    testRoot();
    testZero();
    test1();
    test2();
    test3();
    return 0;
}