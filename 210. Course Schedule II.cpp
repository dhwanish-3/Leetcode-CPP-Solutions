#include <bits/stdc++.h>
using namespace std;

// topological sort using BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> sol;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegrees(numCourses);
        queue<int> q;
        // Building graph
        for (auto prerequsite : prerequisites) {
            int u = prerequsite[1];
            int v = prerequsite[0];
            graph[u].push_back(v);
            inDegrees[v]++;
        }
        // Topology
        for (int i=0 ; i < numCourses ; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            sol.push_back(u);
            for (auto v : graph[u]) {
                if(--inDegrees[v] == 0) {
                    q.push(v);
                }
            }
        }
        return sol.size() == numCourses ? sol : vector<int> ();
    }
};

int main(){
    
    
    return 0;
}