#include <bits/stdc++.h>
using namespace std;

// input n >= 3
class Solution {
    // Approach 1 : DP - memoization
    int recursion(int n, vector<int>& dp) {
        if (n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int maxProduct = 2;
        for (int i = n - 1; i > 0; i--) {
            maxProduct = max(maxProduct, i * recursion(n - i, dp));
        }
        return dp[n] = maxProduct;
    }
public:
    // Approach 2 : DP - Tabalation - O(n^2)
    int integerBreakN2(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector<int> dp(n + 1, 1);
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            for (int j = i - 1; j > 0; j--) {
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
    // Approach 3 : DP - Tabulation - O(n)
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector<int> dp(n + 1, 1);
        dp[2] = 2;
        dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
        }
        return dp[n];
    }
    // Approach 4 : Math - O(1)
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