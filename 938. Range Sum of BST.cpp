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
    int inorder(TreeNode* root, int low, int high) {
        int sum = 0;
        if (root != nullptr) {
            sum = inorder(root->left, low, high);
            if (root->val >= low && high >= root->val) {
                sum += root->val;
            }
            sum += inorder(root->right, low, high);
        }
        return sum;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    }
};

int main() {
    
    return 0;
}