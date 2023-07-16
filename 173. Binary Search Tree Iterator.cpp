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

class BSTIterator {
    int it = 0;
    vector<int> values;
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        if(root->left) inorder(root->left);
        values.push_back(root->val);
        if(root->right) inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        it++;
        return values[it-1];
    }
    
    bool hasNext() {
        return it < values.size();
    }
};

int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
    return 0;
}