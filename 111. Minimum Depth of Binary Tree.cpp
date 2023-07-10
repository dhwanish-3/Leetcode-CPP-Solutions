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

// BFS Bottom - up
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int min = 0;
        queue<TreeNode*> q{{root}};
        while(!q.empty()) {
            min++;
            for(int i=q.size(); i>0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->right == nullptr && node->left == nullptr){
                    return min;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return min;
    }
};

int main(){
    
    
    return 0;
}