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
    void inorder(TreeNode* root, int& prev, int& count, int& maxCount, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, prev, count, maxCount, res);
        if (root->val == prev) {
            count++;
        } else {
            count = 1;
        }
        if (count == maxCount) {
            res.push_back(root->val);
        } else if (count > maxCount) {
            res.clear();
            res.push_back(root->val);
            maxCount = count;
        }
        prev = root->val;
        inorder(root->right, prev, count, maxCount, res);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxCount = 0;
        int count = 0;
        int prev = INT_MIN;
        inorder(root, prev, count, maxCount, res);
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    vector<int> res = Solution().findMode(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}