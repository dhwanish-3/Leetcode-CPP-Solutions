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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        int i = 0;
        while (!q.empty()) {
            int size = q.size();
            int prev = 0;
            for (int j = 0; j < size; j++) {
                TreeNode* node = q.front();
                q.pop();
                if ((i & 1) == 0) {
                    if ((node->val & 1) == 0 || (j != 0 && prev >= node->val)) {
                        return false;
                    }
                } else {
                    if ((node->val & 1) != 0 || (j != 0 && prev <= node->val)) {
                        return false;
                    }
                }
                prev = node->val;
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
            i++;
        }
        return true;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);
    cout << Solution().isEvenOddTree(root);
    return 0;
}