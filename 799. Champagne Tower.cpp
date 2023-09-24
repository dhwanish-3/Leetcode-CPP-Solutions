#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int rows, int glass) {
        vector<vector<double>> dp(rows + 1);
        for (int i = 0; i < rows + 1; i++) {
            dp[i] = vector<double>(i + 1, 0);
        }
        dp[0][0] = poured;
        for (int i = 1; i < rows + 1; i++) {
            dp[i][0] = (dp[i - 1][0] > 1) ? (dp[i - 1][0] - 1) / 2 : 0;
            dp[i][i] = (dp[i - 1][i - 1] > 1) ? (dp[i - 1][i - 1] - 1) / 2 : 0;
            for (int j = 1; j < i; j++) {
                dp[i][j] += dp[i - 1][j - 1] > 1 ? (dp[i - 1][j - 1] - 1) / 2 : 0;
                dp[i][j] += dp[i - 1][j] > 1 ? (dp[i - 1][j] - 1) / 2 : 0;
            }
        }
        if (dp[rows][glass] <= 0) {
            return 0;
        }
        return dp[rows][glass] > 1 ? 1 : dp[rows][glass];
    }
};

int main() {
    int poured, rows, glass;
    cin >> poured >> rows >> glass;
    cout << Solution().champagneTower(poured, rows, glass) << endl;
    return 0;
}