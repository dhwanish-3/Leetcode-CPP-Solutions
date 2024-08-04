#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(string w1, string w2, int i, int j, vector<vector<int>>& dp) {
        if (i == w1.length() && j == w2.length()) {
            return 0;
        } else if (j == w2.length()) {
            return w1.length() - i;
        } else if (i == w1.length()) {
            return w2.length() - j;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (w1[i] == w2[j]) {
            return dp[i][j] = rec(w1, w2, i + 1, j + 1, dp);
        } else {
            int insert = rec(w1, w2, i, j + 1, dp);
            int dele = rec(w1, w2, i + 1, j, dp);
            int replace = rec(w1, w2, i + 1, j + 1, dp);
            return dp[i][j] = 1 + min(insert, dele < replace ? dele : replace);
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; i++) {
            dp[i][n2] = n1 - i;
        }
        for (int j = 0; j < n2; j++) {
            dp[n1][j] = n2 - j;
        }
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j + 1], dp[i + 1][j] < dp[i + 1][j + 1] ? dp[i + 1][j] : dp[i + 1][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};