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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

int main(){
    Solution sol;
    vector<TreeNode*> res = sol.generateTrees(3);
    for (TreeNode* root : res) {
        cout << root->val << endl;
    }
    return 0;
}