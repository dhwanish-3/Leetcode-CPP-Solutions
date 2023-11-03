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
    int sol = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        if (root->val == sum / count) {
            sol++;
        }
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root);
        return sol;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << Solution().averageOfSubtree(root);
    return 0;
}