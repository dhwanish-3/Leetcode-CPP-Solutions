#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int size = roads.size();
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        int sol = 0;
        for (int i = 0; i < size; i++) {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
            connected[roads[i][1]][roads[i][0]] = true;
            connected[roads[i][0]][roads[i][1]] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (connected[i][j]) {
                    sol = max(sol, degree[i] + degree[j] - 1);
                } else {
                    sol = max(sol, degree[i] + degree[j]);
                }
            }
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> k >> n;
    vector<vector<int>> roads(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }
    cout << Solution().maximalNetworkRank(k, roads);
    return 0;
}