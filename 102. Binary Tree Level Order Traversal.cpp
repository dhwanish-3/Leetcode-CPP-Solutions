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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q{{root}};
        vector<vector<int>> sol;
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            for (int i=0 ; i<size ; i++) {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            sol.push_back(v);
        }
        return sol;
    }
};

int main(){
    TreeNode* h = new TreeNode(3);
    h->left = new TreeNode(9);
    h->right = new TreeNode(20);
    h->right->left = new TreeNode(15);
    h->right->right = new TreeNode(7);
    vector<vector<int>> sol = Solution().levelOrder(h);
    for(int i=0; i<sol.size() ;i++ ){
        for (int j=0; j<sol[i].size() ;j++) {
            cout<<sol[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}