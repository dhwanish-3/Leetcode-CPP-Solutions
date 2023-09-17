#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n));
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }
        while (!q.empty()) {
            auto [node, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                return dist;
            }
            for (int next : graph[node]) {
                int next_mask = mask | (1 << next);
                if (!visited[next][next_mask]) {
                    q.push({next, next_mask, dist + 1});
                    visited[next][next_mask] = true;
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> graph = {{1,2,3},{0},{0},{0}};
    cout << Solution().shortestPathLength(graph) << endl;
    return 0;
}