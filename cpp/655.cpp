#include <cmath>

#include <iostream>
#include <string>
#include <vector>

#include "print.cpp"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int middleIndex(int lo, int hi) {
    return lo + (hi-lo)/2;
}


int getTreeHeight(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        return 1;
    } else {
        int left = getTreeHeight(root->left);
        int right = getTreeHeight(root->right);
        return (left>=right) ? left+1 : right+1;
    }
}


// fill an intialized vector based on root TreeNode
void fillVector(TreeNode* root, vector<vector<string>> &v,
                int level, int lo, int hi) {
    if (!root) return;
    int mid = middleIndex(lo, hi);
    v[level][mid] = to_string(root->val);
    if (root->left || root->right) {  // not leaf
        fillVector(root->left, v, level+1, lo, mid-1);
        fillVector(root->right, v, level+1, mid+1, hi);
    }
}


vector< vector<string> > printTree(TreeNode* root) {
    int height = getTreeHeight(root);
    int length = pow(2, height) - 1;
    vector<vector <string>> ret;
    for (int i = 0; i < height; ++i) {
        vector<string> tmp (length, "x");
        ret.push_back(tmp);
    }
    fillVector(root, ret, 0, 0, length-1);
    return ret;
}


void testPrint() {
    vector<vector <string>> ret;
    for (int i=0; i<4; ++i) {
        vector<string> tmp (5, "");
        ret.push_back(tmp);
    }
    printVOV(ret);
}


void test1() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    t1.left = &t2;
    vector<vector <string>> res = printTree(&t1);
    printVOV(res);
}


void test2() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    TreeNode t4 = TreeNode(4);
    t1.left = &t2;
    t1.right = &t3;
    t2.right = &t4;
    vector<vector <string>> res = printTree(&t1);
    printVOV(res);
}


void test3() {
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    TreeNode t4 = TreeNode(4);
    TreeNode t5 = TreeNode(5);
    t1.left = &t2;
    t1.right = &t5;
    t2.left = &t3;
    t3.left = &t4;
    vector<vector <string>> res = printTree(&t1);
    printVOV(res);
}


int main() {
    // testPrint();
    test1();
    test2();
    test3();
    return 0;
}