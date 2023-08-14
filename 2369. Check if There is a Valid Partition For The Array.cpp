#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool partition(vector<int>& nums, int n, int i, vector<int>& dp) {
        if (i == n) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            if (partition(nums, n, i + 2, dp)) {
                return true;
            }
            if (i + 2 < n && nums[i] == nums[i + 2]) {
                if (partition(nums, n, i + 3, dp)) {
                    return true;
                }
            }
        }
        if (i + 2 < n && nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2) {
            if (partition(nums, n ,i + 3, dp)) {
                return true;
            }
        }
        dp[i] = false;
        return dp[i];
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return partition(nums, n, 0, dp);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().validPartition(nums);
    return 0;
}