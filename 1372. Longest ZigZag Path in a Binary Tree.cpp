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
    void maxZigZag(TreeNode* node, int l, int r, int& sol) {
        if (node == nullptr) {
            return;
        }
        sol = max(sol, l);
        sol = max(sol, r);
        maxZigZag(node->left, 0, l + 1, sol);
        maxZigZag(node->right, r + 1, 0, sol);
    }
public:
    int longestZigZag(TreeNode* root) {
        int sol = 0;
        maxZigZag(root, 0, 0, sol);
        return sol;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    cout << Solution().longestZigZag(root);
    return 0;
}