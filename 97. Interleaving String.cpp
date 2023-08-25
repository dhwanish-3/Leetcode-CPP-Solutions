#include <bits/stdc++.h>
using namespace std;


// Approach 1: DP - Memoization
class Solution {
    bool dfs(string s1, string s2, string s3, int i, int j, int k, vector<vector<bool>>& dp) {
        if (dp[i][j]) {
            return false;
        }
        if (k == s3.length()) {
            return true;
        }
        bool valid = (i < s1.length() && s1[i] == s3[k] && dfs(s1, s2, s3, i + 1, j, k + 1, dp)) || (j < s2.length() && s2[j] == s3[k] && dfs(s1, s2, s3, i, j + 1, k + 1, dp));
        if (!valid) {
            dp[i][j] = true;
        }
        return valid;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len = s3.length();
        int first = s1.length();
        int second = s2.length();
        if (first + second != len) {
            return false;
        }
        vector<vector<bool>> dp(first + 1, vector<bool>(second + 1, false));
        return dfs(s1, s2, s3, 0, 0, 0, dp);
    }
};

// Approach 2: DP - Tabulation
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len = s3.length();
        int first = s1.length();
        int second = s2.length();
        if (first + second != len) {
            return false;
        }
        vector<vector<bool>> dp(first + 1, vector<bool>(second + 1, false));
        for (int  i = 0; i <= first; i++) {
            for (int j = 0; j <= second; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] && s3[i + j -1] == s2[j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] && s3[i + j - 1] == s1[i - 1];
                } else {
                    dp[i][j] = (dp[i][j - 1] && s3[i + j -1] == s2[j - 1]) || (dp[i- 1][j] && s3[i + j - 1] == s1[i - 1]);
                }
            }
        }
        return dp[first][second];
    }
};

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << Solution().isInterleave(s1, s2, s3);
    return 0;
}