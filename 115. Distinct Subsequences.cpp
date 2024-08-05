#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (i >= s.length() && j >= t.length()) {
            return 1;
        }
        if (i >= s.length()) return 0;
        if (j >= t.length()) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) 
            return dp[i][j] = rec(s, t, i + 1, j + 1, dp) + rec(s, t, i + 1, j, dp);
        return dp[i][j] = rec(s, t, i + 1, j, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[n][m] = 1;
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = (long)dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};