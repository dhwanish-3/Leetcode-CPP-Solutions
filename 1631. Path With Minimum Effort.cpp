#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!pq.empty()) {
            int i = pq.top().first;
            int j = pq.top().second;
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < 0 || y < 0 || x >= n || y >= m) {
                    continue;
                }
                int diff = abs(heights[x][y] - heights[i][j]);
                int maxDiff = max(diff, dp[i][j]);
                if (maxDiff < dp[x][y]) {
                    dp[x][y] = maxDiff;
                    pq.push({x, y});
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; i < m; j++) {
            cin >> heights[i][j];
        }
    }
    cout << Solution().minimumEffortPath(heights) << endl;
    return 0;
}