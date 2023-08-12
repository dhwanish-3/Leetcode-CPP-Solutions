#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursion - TLE
class Solution {
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& count) {
        if (i == m && j == n) {
            count++;
            return;
        }
        if (i > m || j > n || grid[i][j] == 1) {
            return;
        }
        dfs(grid, m ,n, i + 1, j, count);
        dfs(grid, m ,n, i, j + 1, count);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.size();
        int count  = 0;
        dfs(obstacleGrid, m - 1, n - 1, 0 , 0, count);
        return count;
    }
};

// Approach 2: 2D DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = grid[i - 1][j - 1] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

// Approach 3: 1D DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = grid[i][j] == 1 ? 0 : dp[j] + (j > 0 ? dp[j - 1] : 0);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }
    cout << Solution().uniquePathsWithObstacles(obstacleGrid);
    return 0;
}