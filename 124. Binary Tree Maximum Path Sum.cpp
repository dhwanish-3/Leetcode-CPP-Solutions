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
    int maxPathFrom(TreeNode* root, int& sol) {
        if (root == nullptr) return 0;
        int l = max(0, maxPathFrom(root->left, sol));
        int r = max(0, maxPathFrom(root->right, sol));
        sol = max(sol, root->val+l+r);
        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sol = INT_MIN;
        maxPathFrom(root, sol);
        return sol;
    }
};

int main(){
    TreeNode* h = new TreeNode(-10);
    h->left = new TreeNode(9);
    h->right = new TreeNode(20);
    h->right->left = new TreeNode(15);
    h->right->right = new TreeNode(7);
    cout<<Solution().maxPathSum(h);
    return 0;
}