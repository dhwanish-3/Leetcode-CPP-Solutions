#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    int rec(int n, int i) {
        if (n == 0) return 1;
        if (dp[n][i] != -1) return dp[n][i];
        int sol = 0;
        for (int x = i; x < 5; x++) {
            sol += rec(n - 1, x);
        }
        return dp[n][i] = sol;
    }
public:
    int countVowelStrings(int n) {
        dp.resize(n + 1, vector<int>(6, 0));
        for (int i = 0; i <= 5; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 5; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n][5];
    }
};