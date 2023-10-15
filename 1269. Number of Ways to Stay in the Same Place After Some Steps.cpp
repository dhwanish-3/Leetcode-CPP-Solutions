#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Recursion -> Memoization - Memmory Limit Exceeded
class Solution1 {
    int mod = 1e9 + 7;
    int recursion(int steps, int pos, int arrLen, vector<vector<int>>& dp) {
        if (steps == 0) {
            if (pos == 0) {
                return 1;
            }
            return 0;
        }
        if (dp[steps][pos] != -1) {
            return dp[steps][pos];
        }
        int left = 0, right = 0, stay = 0;
        if (pos > 0) {
            left = recursion(steps - 1, pos - 1, arrLen, dp);
        }
        if (pos < arrLen - 1) {
            right = recursion(steps - 1, pos + 1, arrLen, dp);
        }
        stay = recursion(steps - 1, pos, arrLen, dp);
        return dp[steps][pos] = ((left % mod + stay % mod) % mod + right % mod) % mod;
    }
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen, -1));
        return recursion(steps, 0, arrLen, dp);
    }
};

// Approach 2 : DP - Tabulation
class Solution {
    int mod = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= arrLen; j++) {
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                if (j < arrLen - 1) {
                    dp[i][j] = (dp[i][j] +  dp[i - 1][j + 1]) % mod;
                }
                dp[i][j] = (dp[i][j] +  dp[i - 1][j]) % mod;
            }
        }
        return dp[steps][0] % mod;
    }
};

// Approach 3 : DP - Tabulation - Space Optimized
class Solution {
    int mod = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        vector<int> cur(arrLen, 0);
        vector<int> prev(arrLen, 0);
        prev[0] = 1;
        for (int i = 1; i <= steps; i++) {
            cur = vector<int>(arrLen, 0);
            for (int j = 0; j < arrLen; j++) {
                if (j > 0) {
                    cur[j] = (cur[j] + prev[j - 1]) % mod;
                }
                if (j < arrLen - 1) {
                    cur[j] = (cur[j] +  prev[j + 1]) % mod;
                }
                cur[j] = (cur[j] + prev[j]) % mod;
            }
            prev = cur;
        }
        return prev[0] % mod;
    }
};

int main() {
    int steps, arrLen;
    cin >> steps >> arrLen;
    Solution sol;
    cout << sol.numWays(steps, arrLen) << endl;
    return 0;
}