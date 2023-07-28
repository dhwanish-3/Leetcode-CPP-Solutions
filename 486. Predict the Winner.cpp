#include <bits/stdc++.h>
using namespace std;

// Approach 1: 2D DP
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                dp[j][j + i] = max(nums[j + 1] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

// Approach 2: 1D DP
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        for (int d = 0; d < n; d++) {
            for (int j = n - 1; j - d >= 0; j--) {
                int i = j - d;
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().PredictTheWinner(nums);
    return 0;
}