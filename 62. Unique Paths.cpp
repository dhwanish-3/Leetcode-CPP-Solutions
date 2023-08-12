#include <bits/stdc++.h>
using namespace std;

// Approach 1: Dynamic Programming - Memoization
class Solution {
    int dfs(vector<vector<int>>& dp, int m, int n, int i, int j) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = dfs(dp, m, n, i + 1, j) + dfs(dp, m, n, i, j + 1);
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(dp, m, n, 0, 0);
    }
};

// Approach 2: Math - Combinatorics
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int k = m - 1;
        double res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (N - k + i) / i;
        }
        return (int)res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    cout << Solution().uniquePaths(n, m) << endl;
    return 0;
}