#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(string s, int l, int r, vector<vector<int>>& dp) {
        if (l == r) return 1;
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        if (s[l] == s[r]) return dp[l][r] = 2 + rec(s, l + 1, r - 1, dp);
        return dp[l][r] = max(rec(s, l + 1, r, dp), rec(s, l, r - 1, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][i] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};