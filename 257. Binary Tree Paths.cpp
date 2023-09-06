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
    void inorder(TreeNode* root, vector<string>& sol, string s) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            s += to_string(root->val);
            sol.push_back(s);
        }
        s += to_string(root->val);
        s += "->";
        inorder(root->left, sol, s);
        inorder(root->right, sol, s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sol;
        inorder(root, sol, "");
        return sol;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    vector<string> sol = Solution().binaryTreePaths(root);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}