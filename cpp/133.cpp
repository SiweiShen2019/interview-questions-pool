#include <iostream>
#include <vector>

#include "print.cpp"

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


void backTrack(TreeNode *root, int sum, vector<vector<int>> &dest,
               vector<int> &tmp) {
    if (!root) return;
    int rootVal{root->val};
    tmp.push_back(rootVal);
    if (isLeaf(*root)) {
        if (rootVal == sum) {
            dest.push_back(tmp);
        }
        tmp.pop_back();
        return;
    }
    backTrack(root->left, sum-rootVal, dest, tmp);
    backTrack(root->right, sum-rootVal, dest, tmp);
    tmp.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ret;
    if (!root) return ret;
    vector<int> tmp;
    backTrack(root, sum, ret, tmp);
    return ret;
}


void testPrint() {
    vector<vector<int>> v;
    printVOV(v);
    v.push_back(vector<int>{1});
    printVOV(v);
}


void test1() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    t1.left = &t2;
    t1.right = &t3;
    vector<vector<int>> v{pathSum(&t1, 3)};
    printVOV(v);
}

void testSamePath() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(2);
    t1.left = &t2;
    t1.right = &t3;
    vector<vector<int>> v{pathSum(&t1, 3)};
    printVOV(v);
}

/*
     1
   /  \
  3   2
 /     \
7       8
*/
void testSimple() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(3);
    TreeNode t3 = TreeNode(2);
    TreeNode t4 = TreeNode(7);
    TreeNode t5 = TreeNode(8);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t3.right = &t5;
    vector<vector<int>> v{pathSum(&t1, 11)};
    printVOV(v);
}


void test2() {
    TreeNode t1 = TreeNode(5);
    TreeNode t2 = TreeNode(4);
    TreeNode t3 = TreeNode(8);
    TreeNode t4 = TreeNode(11);
    TreeNode t5 = TreeNode(13);
    TreeNode t6 = TreeNode(4);
    TreeNode t7 = TreeNode(7);
    TreeNode t8 = TreeNode(2);
    TreeNode t9 = TreeNode(5);
    TreeNode t10 = TreeNode(1);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t3.left = &t5;
    t3.right = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t6.left = &t9;
    t6.right = &t10;
    vector<vector<int>> v{pathSum(&t1, 22)};
    printVOV(v);
}


int main() {
    // testPrint();
    test1();
    testSamePath();
    testSimple();
    test2();
    return 0;
}
