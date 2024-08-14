#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Approach 1
    int recursion(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 0;
        }
        if (dp[i][j + 1] != -1) {
            return dp[i][j + 1];
        }
        if (j != -1 && nums[i] <= nums[j]) {
            return dp[i][j + 1] = recursion(nums, i + 1, j, dp);
        }
        return dp[i][j + 1] = max(1 + recursion(nums, i + 1, i, dp), recursion(nums, i + 1, j, dp));
    }
public:
    int Memoization(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return recursion(nums, 0, -1, dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                if (j != -1 && nums[i] <= nums[j]) {
                    dp[i][j + 1] = dp[i + 1][j + 1];
                } else {
                    dp[i][j + 1] = max(1 + dp[i + 1][i + 1], dp[i + 1][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
    int spaceOptimized(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), cur(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                if (j != -1 && nums[i] <= nums[j]) {
                    cur[j + 1] = next[j + 1];
                } else {
                    cur[j + 1] = max(1 + next[i + 1], next[j + 1]);
                }
            }
            next = cur;
        }
        return next[0];
    }
    // new Approach
    int newApproach(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

// Using Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> subSequence;
        subSequence.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (subSequence[subSequence.size() - 1] < nums[i]) {
                subSequence.push_back(nums[i]);
            } else {
                auto it = lower_bound(subSequence.begin(), subSequence.end(), nums[i]);
                *it = nums[i];
            }
        }
        return subSequence.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().newApproach(nums);
    return 0;
}