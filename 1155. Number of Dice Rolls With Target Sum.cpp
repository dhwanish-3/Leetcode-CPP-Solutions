#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
    int recursion(int i, int k, int target, vector<vector<int>>& dp) {
        if (i == -1) {
            return 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        } 
        if (target > k * i || target < i) {
            return dp[i][target] = 0;
        }
        if (target == i || target == k * i) {
            return dp[i][target] = 1;
        }
        int count = 0;
        for (int j = 1; j <= k; j++) {
            if (target >= j) {
                count = (count + recursion(i - 1, k, target - j, dp) % mod) % mod;
            } else {
                break;
            }
        }
        return dp[i][target] = count % mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return recursion(n, k, target, dp);
    }
};

int main() {
    int n, k, target;
    cin >> n >> k >> target;
    cout << Solution().numRollsToTarget(n, k, target);
    return 0;
}