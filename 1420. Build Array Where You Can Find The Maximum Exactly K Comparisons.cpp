#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
    int recursion(int n, int i, int m, int k, vector<vector<vector<int>>>& dp) {
        if (n <= 0) {
            if (k == 0) {
                return 1;
            }
            return 0;
        }
        if (dp[n][k][i] != -1) {
            return dp[n][k][i];
        }
        int sol = 0;
        for (int j = 1; j <= m; j++) {
            if (j > i) {
                if (n >= 1 && k >= 1)
                sol = (sol + recursion(n - 1, j, m, k - 1, dp)) % mod;
            } else {
                if (n >= 1)
                sol = (sol + recursion(n - 1, i, m, k, dp)) % mod;
            }
        }
        return dp[n][k][i] = sol % mod;
    }
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
        return recursion(n, 0, m, k, dp) % mod;
    }
};

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    cout << Solution().numOfArrays(n, m, k) << endl;
    return 0;
}