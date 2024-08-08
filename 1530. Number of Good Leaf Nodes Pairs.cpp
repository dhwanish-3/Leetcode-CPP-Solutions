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
    vector<int> dfs(TreeNode* root, int dist) {
        vector<int> p;
        if (!root) return p;
        vector<int> left = dfs(root->left, dist);
        vector<int> right = dfs(root->right, dist);
        if (left.empty() && right.empty()) {
            p.push_back(1);
            return p;
        }
        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] <= dist) {
                    sol++;
                }
            }
        }
        for (int i = 0; i < left.size(); i++) {
            left[i]++;
            p.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            right[i]++;
            p.push_back(right[i]);
        }
        return p;
    }
public:
    int countPairs(TreeNode* root, int dist) {
        dfs(root, dist);
        return sol;
    }
};