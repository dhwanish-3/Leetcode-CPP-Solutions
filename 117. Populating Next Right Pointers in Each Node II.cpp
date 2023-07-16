#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> q{{root}};
        while (!q.empty()) {
            int size = q.size();
            for (int i=0 ; i<size ; i++) {
                Node* node = q.front();
                q.pop();
                if (!q.empty() && i < size-1) {
                    node->next = q.front();
                    cout<<node->next->val<<" ";
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            cout<<endl;
        }
        return root;
    }
};

void inorder(Node* root) {
    if(root != nullptr) {
        inorder(root->left);
        cout<<root->val<<" has next = ";
        if(root->next) cout<<root->next->val<<endl;
        else cout<<"null"<<endl;
        inorder(root->right);
    }
}

int main(){
    Node* n = new Node(1);
    n->left = new Node(2);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->left->right->right = new Node(200);
    n->right = new Node(3);
    n->right->left = new Node(10);
    n->right->right = new Node(7);
    n->right->right->left = new Node(100);
    Node* sol = Solution().connect(n);
    inorder(sol);
    return 0;
}