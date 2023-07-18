#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        queue<Node*> q{{node}};
        unordered_map<Node*, Node*> oldToNew{{node, new Node(node->val)}};
        while (!q.empty()) {
            Node* u = q.front();
            q.pop();
            int size = u->neighbors.size();
            for (int i=0 ; i<size ; i++) {
                Node* v = u->neighbors[i];
                if (!oldToNew.count(v)) {
                    oldToNew[v] = new Node(v->val);
                    q.push(v);
                }
                oldToNew[u]->neighbors.push_back(oldToNew[v]);
            }
        }
        return oldToNew[node];
    }
};

int main(){
    
    
    return 0;
}