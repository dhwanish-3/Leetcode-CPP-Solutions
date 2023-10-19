#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int parent[n];
        memset(parent, -1, sizeof(parent));
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (parent[leftChild[i]] != -1) {
                    return false;
                }
                parent[leftChild[i]] = i;
            }
            if (rightChild[i] != -1) {
                if (parent[rightChild[i]] != -1) {
                    return false;
                }
                parent[rightChild[i]] = i;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
                break;
            }
        }
        if (root == -1) {
            return false;
        }
        bool visited[n];
        memset(visited, false, sizeof(visited));
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur]) {
                return false;
            }
            visited[cur] = true;
            if (leftChild[cur] != -1) {
                q.push(leftChild[cur]);
            }
            if (rightChild[cur] != -1) {
                q.push(rightChild[cur]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> leftChild(n);
    for (int i = 0; i < n; i++) {
        cin >> leftChild[i];
    }
    vector<int> rightChild(n);
    for (int i = 0; i < n; i++) {
        cin >> rightChild[i];
    }
    cout << Solution().validateBinaryTreeNodes(n, leftChild, rightChild) << endl;
    return 0;
}