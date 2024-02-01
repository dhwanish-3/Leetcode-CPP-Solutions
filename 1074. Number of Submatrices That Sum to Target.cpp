#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            for (int j = 1; j <= m; ++j) {
                sum += matrix[i - 1][j - 1];
                dp[i][j] = dp[i - 1][j] + sum;
            }
        }
        int sol = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                for (int k = 1; k <= m; ++k) {
                    int sum = dp[j][k] - dp[i - 1][k];
                    sol += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return sol;
    }
};

int main() {
    int n, target;
    cin >> n >> target;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << Solution().numSubmatrixSumTarget(matrix, target) << endl;
    return 0;
}