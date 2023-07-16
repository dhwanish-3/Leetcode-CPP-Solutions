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
    void dfs(TreeNode* root, int path, int& sol) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right ==nullptr) {
            sol += path * 10 + root->val;
            return;
        }
        dfs(root->left, path*10 + root->val, sol);
        dfs(root->right, path*10 + root->val, sol);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sol = 0;
        dfs(root, 0, sol);
        return sol;
    }
};

int main(){
    
    
    return 0;
}