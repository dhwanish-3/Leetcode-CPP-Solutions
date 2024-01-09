#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int sol = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                long long diff = (long long)nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff] + 1;
                    sol += dp[j][diff];
                } else {
                    dp[i][diff]++;
                }
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().numberOfArithmeticSlices(nums);
    return 0;
}