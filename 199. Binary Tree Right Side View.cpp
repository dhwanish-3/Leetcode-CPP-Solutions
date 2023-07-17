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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q{{root}};
        vector<int> sol;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0 ; i<size ; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == size-1) sol.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return sol;
    }
};

int main(){
    TreeNode* h = new TreeNode(1);
    h->left = new TreeNode(2);
    h->left->right = new TreeNode(5);
    h->right = new TreeNode(3);
    h->right->left = new TreeNode(15);
    h->right->right = new TreeNode(4);
    vector<int> sol = Solution().rightSideView(h);
    for (int i=0; i<sol.size();i++) cout<<sol[i]<<" ";
    return 0;
}