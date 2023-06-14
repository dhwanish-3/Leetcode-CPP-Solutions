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
    int minDiff = INT_MAX;
    int prev = -999999;
public:
    void inorderBST(TreeNode* root){
        if(root->left!=nullptr) inorderBST(root->left);
        minDiff=min(minDiff,root->val-prev);
        prev=root->val;
        if(root->right!=nullptr) inorderBST(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorderBST(root);
        return minDiff;
    }
};

TreeNode* insertBST(TreeNode* root,int val){
    TreeNode* node=new TreeNode(val);
    if(root==nullptr){
        root=node;
    }else{
        TreeNode* currNode=root;
        TreeNode* add=nullptr;
        while(currNode){
            add=currNode;
            if(node->val<currNode->val){
                currNode=currNode->left;
            }else{
                currNode=currNode->right;
            }
        }
        if(add->val>node->val){
            add->left=node;
        }else{
            add->right=node;
        }
    }
    return root;
}

void printBST(TreeNode* root){
    if(root!=nullptr){
        printBST(root->left);
        cout<<root->val<<" ";
        printBST(root->right);
    }
}

int main(){
    int n,in;
    cin>>n;
    TreeNode* root=nullptr;
    while(n--){
        cin>>in;
        root=insertBST(root,in);
    }
    // printBST(root);
    cout<<Solution().getMinimumDifference(root);
    return 0;
}