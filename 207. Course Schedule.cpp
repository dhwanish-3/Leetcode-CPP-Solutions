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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, -1);
        for (int i=0 ; i<n ; i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            graph[u].push_back(v);
        }
        for (int i=0 ; i<numCourses ; i++) {
            if (hasCycle(graph, i, visited))
                return false;
        }
        return true;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v(n,vector<int>(2));
    for (int i=0 ; i<n; i++) cin>>v[i][0]>>v[i][1];
    cout<<Solution().canFinish(k, v);
    return 0;
}