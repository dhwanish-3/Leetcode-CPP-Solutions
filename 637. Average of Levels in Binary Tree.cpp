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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        vector<double> sol;
        while (!q.empty()) {
            long sum = 0;
            int size = q.size();
            for (int i=0 ; i<size ; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            sol.push_back(sum / (double)size);
        }
        return sol;
    }
};

int main(){
    
    
    return 0;
}