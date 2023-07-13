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
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i=0 ; i<n; i++) 
        for (int j=0 ; j<n; j++)
            cin>>v[i][j];
    vector<int> sol = Solution().eventualSafeNodes(v);
    for (int i=0 ;i<sol.size() ; i++) 
        cout<<sol[i]<<" ";
    return 0;
}