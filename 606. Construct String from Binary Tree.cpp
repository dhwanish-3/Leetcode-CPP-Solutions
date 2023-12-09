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
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string s = to_string(root->val);
        if (root->left != nullptr) {
            s += "(" + tree2str(root->left) + ")";
        } else if (root->right != nullptr) {
            s += "()";
        }
        if (root->right != nullptr) {
            s += "(" + tree2str(root->right) + ")";
        }
        return s;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    cout << Solution().tree2str(root);
    return 0;
}