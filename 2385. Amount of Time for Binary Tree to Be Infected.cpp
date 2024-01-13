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
    int amountOfTime(TreeNode* root, int start) {
        // first creating a undirected graph
        unordered_map<int, vector<int>> graph;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                graph[curr->val].push_back(curr->left->val);
                graph[curr->left->val].push_back(curr->val);
                q.push(curr->left);
            }
            if (curr->right) {
                graph[curr->val].push_back(curr->right->val);
                graph[curr->right->val].push_back(curr->val);
                q.push(curr->right);
            }
        }
        // now we have the graph, we can do a bfs
        unordered_set<int> visited;
        queue<int> q2;
        q2.push(start);
        visited.insert(start);
        int time = 0;
        while (!q2.empty()) {
            int size = q2.size();
            for (int i = 0; i < size; i++) {
                int curr = q2.front();
                q2.pop();
                for (int neighbor : graph[curr]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q2.push(neighbor);
                    }
                }
            }
            time++;
        }
        return time - 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(8);
    cout << Solution().amountOfTime(root, 4) << endl;
    return 0;
}