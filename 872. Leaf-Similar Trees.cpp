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
    void inorder(TreeNode* root, vector<int>& in) {
        if (root) {
            inorder(root->left, in);
            if (root->left == nullptr && root->right == nullptr) {
                in.push_back(root->val);
            }
            inorder(root->right, in);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left, right;
        inorder(root1, left);
        inorder(root2, right);
        int l = left.size();
        int r = right.size();
        if (l != r) {
            return false;
        }
        for (int i = 0; i < l; i++) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    cout << Solution().leafSimilar(root1, root2) << endl;
    return 0;
}