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
    bool validBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) {
            return true;
        }
        if (min && root->val <= min->val) {
            return false;
        }
        if (max && root->val >= max->val) {
            return false;
        }
        return validBST(root->left, min, root) && validBST(root->right, root, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, nullptr, nullptr);
    }
};

int main(){
    TreeNode* h = new TreeNode(5);
    h->left = new TreeNode(1);
    h->right = new TreeNode(6);
    h->right->left = new TreeNode(5);
    h->right->right = new TreeNode(8);
    cout<<Solution().isValidBST(h);
    return 0;
}