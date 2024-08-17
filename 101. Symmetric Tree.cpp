#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool symmetric(TreeNode* x, TreeNode* y) {
        if (x && y) {
            return x->val==y->val && symmetric(x->left, y->right) && symmetric(x->right, y->left);
        } else {
            return x==y;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        return symmetric(root, root);
    }
};