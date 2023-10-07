#include <bits/stdc++.h>
using namespace std;

// Approach 3: DP - Memoization
class Solution {
    int recursion(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int left = nums[i] - recursion(nums, i + 1, j, dp);
        int right = nums[j] - recursion(nums, i, j - 1, dp);
        return dp[i][j] = max(left, right);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursion(nums, 0, n - 1, dp) >= 0;
    }
};

// Approach 2: 2D DP
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

// Approach 3: 1D DP
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