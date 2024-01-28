#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { 1 };
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int l = 0; l <= min(j, i - 1); ++l) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % 1000000007;
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    cout << Solution().kInversePairs(n, k) << endl;
    return 0;
}