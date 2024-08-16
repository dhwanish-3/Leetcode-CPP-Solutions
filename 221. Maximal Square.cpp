#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] == '1' ? 1:0;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (dp[i][j] != 0 && dp[i - 1][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j - 1] != 0) {
                    if (dp[i - 1][j] <= dp[i - 1][j - 1])
                        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                    else dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1]);
                }
            }
        }
        int sol = 0;
        for (int i = 0; i < m; i++) {
            sol = max(sol, *max_element(dp[i].begin(), dp[i].end()));
        }
        return sol * sol;
    }
};