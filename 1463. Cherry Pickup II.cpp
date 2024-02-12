#include <bits/stdc++.h>
using namespace std;

class Solution {
    int cherryPickupHelper(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r, int c1, int c2) {
        if (r == grid.size()) {
            return 0;
        }
        if (dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < grid[0].size() && nc2 >= 0 && nc2 < grid[0].size()) {
                    ans = max(ans, cherryPickupHelper(grid, dp, r + 1, nc1, nc2));
                }
            }
        }
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans + cherries;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return cherryPickupHelper(grid, dp, 0, 0, n - 1);
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << Solution().cherryPickup(grid);
    return 0;
}