#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = ((long)dp[i - 1][4] + dp[i - 1][6]) % mod;
            dp[i][1] = ((long)dp[i - 1][6] + dp[i - 1][8]) % mod;
            dp[i][2] = ((long)dp[i - 1][7] + dp[i - 1][9]) % mod;
            dp[i][3] = ((long)dp[i - 1][4] + dp[i - 1][8]) % mod;
            dp[i][4] = ((long)dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][9]) % mod;
            dp[i][5] = 0;
            dp[i][6] = ((long)dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][7]) % mod;
            dp[i][7] = ((long)dp[i - 1][2] + dp[i - 1][6]) % mod;
            dp[i][8] = ((long)dp[i - 1][1] + dp[i - 1][3]) % mod;
            dp[i][9] = ((long)dp[i - 1][2] + dp[i - 1][4]) % mod;
        }
        int sol = 0;
        for (int i = 0; i < 10; i++) {
            sol = (sol + dp[n][i]) % mod;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().knightDialer(n);
    return 0;
}