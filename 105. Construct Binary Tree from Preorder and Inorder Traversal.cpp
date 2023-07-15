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
    TreeNode* buildBinaryTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inToIndex) {
        if (preStart > preEnd) return nullptr;
        int rootVal = preorder[preStart];
        int rootInIndex = inToIndex.at(rootVal);
        int leftSize = rootInIndex - inStart;
        TreeNode* node = new TreeNode(rootVal);
        node->left = buildBinaryTree(preorder, preStart+1, preStart+leftSize, inorder, inStart, rootInIndex-1, inToIndex);
        node->right = buildBinaryTree(preorder, preStart+leftSize+1, preEnd, inorder, rootInIndex+1, inEnd, inToIndex);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderToIndex;
        int n = preorder.size();
        for (int i=0 ; i<n ; i++) {
            inorderToIndex[inorder[i]] = i;
        }
        return buildBinaryTree(preorder, 0, n-1, inorder, 0, n-1, inorderToIndex);
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
    vector<int> pre(n);
    for (int i=0 ; i<n ; i++) cin>>pre[i];
    for (int i=0 ; i<n ; i++) cin>>in[i];
    TreeNode* sol  = Solution().buildTree(pre, in);
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