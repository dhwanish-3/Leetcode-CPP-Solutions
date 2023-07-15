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
    TreeNode* buildBinaryTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inToIndex) {
        if (inStart > inEnd) return nullptr;
        int rootVal = postorder[postEnd];
        int rootInIndex = inToIndex.at(rootVal);
        int leftSize = rootInIndex - inStart;
        TreeNode* node = new TreeNode(rootVal);
        node->left = buildBinaryTree(inorder, inStart, rootInIndex-1, postorder, postStart, postStart+leftSize-1, inToIndex);
        node->right = buildBinaryTree(inorder, rootInIndex+1, inEnd, postorder, postStart+leftSize, postEnd-1, inToIndex);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inToIndex;
        for (int i=0; i<n ; i++) {
            inToIndex[inorder[i]] = i;
        }
        return buildBinaryTree(inorder, 0, n-1, postorder, 0, n-1, inToIndex);
    }
};

void preorder(TreeNode* root) {
    if(root != nullptr) {
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if(root != nullptr) {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if(root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> in(n);
    vector<int> post(n);
    for (int i=0 ; i<n ; i++) cin>>in[i];
    for (int i=0 ; i<n ; i++) cin>>post[i];
    TreeNode* sol  = Solution().buildTree(in, post);
    cout<<"inorder = ";
    inorder(sol);
    cout<<endl;
    cout<<"preorder = ";
    preorder(sol);
    cout<<endl;
    cout<<"postorder = ";
    postorder(sol);
    return 0;
}