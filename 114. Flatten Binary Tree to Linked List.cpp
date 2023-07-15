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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;
        TreeNode* rightMost = root;
        while (rightMost->right) {
            rightMost = rightMost->right;
        }
        rightMost->right = right;
    }
};

int main(){
    
    
    return 0;
}