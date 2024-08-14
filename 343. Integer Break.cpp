#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rec(int n, int i, vector<vector<int>>& dp) {
        if (n == 0 || i == 0) return 1;
        if (dp[n][i] != -1) return dp[n][i];
        if (i > n) return dp[n][i] = rec(n, i - 1, dp);
        return dp[n][i] = max(i * rec(n - i, i, dp), rec(n, i - 1, dp));
    }
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n, 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                if (j > i)
                    dp[i][j] = dp[i][j - 1];
                else dp[i][j] = max(j * dp[i - j][j], dp[i][j - 1]);
            }
        }
        return dp[n][n - 1];
    }
    int integerBreakMath(int n) {
        if (n < 4) {
            return n - 1;
        }
        int quotient = n / 3;
        if (quotient * 3 == n) {
            return pow(3, quotient);
        } else if (quotient * 3 + 1 == n) {
            return pow(3, quotient - 1) * 4;
        } else {
            return pow(3, quotient) * 2;
        }
    }
};

int main() {
    int n = 10;
    cin >> n;
    cout << Solution().integerBreak(n) << endl;
}