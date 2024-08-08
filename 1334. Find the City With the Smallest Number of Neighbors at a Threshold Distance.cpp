#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> adj(n, vector(n, 10001));
        for (auto& e : edges) 
            adj[e[0]][e[1]] = adj[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; i++) 
            adj[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int curMin = n, sol = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= d) count++;
            }
            if (count <= curMin) {
                sol = i;
                curMin = count;
            }
        }
        return sol;
    }
};