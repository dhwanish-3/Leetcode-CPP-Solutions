#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[0] = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            visited[u] = true;
            res += dist[u];
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    dist[v] = min(dist[v], abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]));
                }
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}