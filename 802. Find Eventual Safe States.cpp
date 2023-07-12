#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool hasCycle(vector<vector<int>>& graph, int u, vector<int>& visited) {
        if(visited[u] == 0) return true;
        if(visited[u] == 1) return false;
        visited[u] = 0;
        for (int v = 0; v < graph[u].size(); v++) {
            if (hasCycle(graph, graph[u][v], visited)) {
                return true;
            }
        }
        visited[u] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        vector<int> sol;
        for (int i = 0; i < n; i++) {
            if(!hasCycle(graph, i, visited)){
                sol.push_back(i);
            }
        }
        return sol;
    }
};

int main(){
    
    
    return 0;
}