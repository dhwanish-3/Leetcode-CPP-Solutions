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
    void inorder(TreeNode* root, int k,int& i, int& sol) {
        if (root == nullptr)
            return;
        inorder(root->left, k, i, sol);
        i++;
        if (i == k) {
            sol = root->val;
            return;
        }
        inorder(root->right, k, i, sol);
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int sol = INT_MAX;
        int i = 0;
        inorder(root, k, i, sol);
        return sol;
    }
};

int main(){
    
    
    return 0;
}