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
    map<int,int> levelSum;
    void levelOrder(TreeNode* root,int level) {
        if(root!=nullptr){
            levelSum[level]+=root->val;
            levelOrder(root->left,level+1);
            levelOrder(root->right,level+1);
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int maxLevel=1;
        levelOrder(root,1);
        for(auto it=levelSum.begin();it!=levelSum.end();it++){
            if(it->second>maxSum){
                maxSum=it->second;
                maxLevel=it->first;
            }
        }
        return maxLevel;
    }
};

TreeNode* insertBinaryTree(TreeNode* root,int val){
    return root;
}

int main(){
    int n,in;
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(7);
    root->right=new TreeNode(-8);
    root->left->left=new TreeNode(7);
    root->left->right=new TreeNode(-8);
    root->right->right=new TreeNode(20);
    root->right->right->left=new TreeNode(12);
    root->left->right->right=new TreeNode(9);
    cout<<Solution().maxLevelSum(root);
    return 0;
}