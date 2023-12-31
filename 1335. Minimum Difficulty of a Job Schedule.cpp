#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);
        }
        for (int i = 1; i < d; i++) {
            for (int j = i; j < n; j++) {
                int maxDifficulty = jobDifficulty[j];
                for (int k = j; k >= i; k--) {
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + maxDifficulty);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> jobDifficulty(n);
    for (int i = 0; i < n; i++) {
        cin >> jobDifficulty[i];
    }
    cout << Solution().minDifficulty(jobDifficulty, d);
    return 0;
}