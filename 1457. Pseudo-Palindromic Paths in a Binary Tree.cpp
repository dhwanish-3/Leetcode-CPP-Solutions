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
    void preorder(TreeNode* root, int path = 0) {
        if (!root) {
            return;
        }
        path ^= (1 << root->val);
        if (!root->left && !root->right) {
            if ((path & (path - 1)) == 0) {
                sol++;
            }
        }
        preorder(root->left, path);
        preorder(root->right, path);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root);
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return 0;
}