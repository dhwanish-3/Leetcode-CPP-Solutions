#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<TreeNode*, int> nodeDistance;
    void getDistances(TreeNode* root, TreeNode* target) {
        if(root == nullptr) return;
        if(root == target) {
            nodeDistance[root] = 0;
            return;
        }
        getDistances(root->left, target);
        auto it = nodeDistance.find(root->left);
        if(it != nodeDistance.end()){
            nodeDistance[root] = it->second + 1;
            return;
        }
        getDistances(root->right, target);
        it = nodeDistance.find(root->right);
        if(it != nodeDistance.end()){
            nodeDistance[root] = it->second + 1;
        }
    }
    void dfs(TreeNode* root, int k, int dist, vector<int>& sol) {
        if(root == nullptr) return;
        auto it = nodeDistance.find(root);
        if(it != nodeDistance.end()){
            dist = it->second;
        }
        if(dist == k){
            sol.push_back(root->val);
        }
        dfs(root->left, k, dist+1, sol);
        dfs(root->right, k, dist+1, sol);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> sol;
        getDistances(root, target);
        dfs(root, k, 0, sol);
        return sol;
    }
};

int main(){
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(5);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(-2);
    head->left->right = new TreeNode(20);
    head->right->right = new TreeNode(10);
    Solution().distanceK(head,head->left,0);
    return 0;
}