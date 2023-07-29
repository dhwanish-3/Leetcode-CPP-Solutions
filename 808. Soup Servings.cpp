#include <bits/stdc++.h>
using namespace std;

class Solution {
    double dfs(vector<vector<double>>& dp, int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0.0;
        }
        if (dp[a][b] > 0) {
            return dp[a][b];
        }
        dp[a][b] = 0.25 * (dfs(dp, a-4, b) + dfs(dp, a-3, b-1) + dfs(dp, a-2, b-2) + dfs(dp, a-1, b-3));
        return dp[a][b];
    }
public:
    double soupServings(int n) {
        if (n >= 5000) {
            return 1.0;
        }
        n = (n + 24) / 25;
        vector<vector<double>> dp(200, vector<double>(200, 0));
        return dfs(dp, n, n);
    }
};

int main(){
    int n;
    cin >> n;
    cout << Solution().soupServings(n);
    return 0;
}