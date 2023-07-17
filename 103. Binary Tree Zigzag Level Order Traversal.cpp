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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q{{root}};
        vector<vector<int>> sol;
        bool reverse = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v(size);
            int index = reverse ? size - 1 : 0;
            for (int i=0 ; i<size ; i++) {
                TreeNode* node = q.front();
                q.pop();
                v[index] = node->val;
                index = reverse ? index-1 : index+1;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            sol.push_back(v);
            reverse = !reverse;
        }
        return sol;
    }
};

int main(){
    
    
    return 0;
}