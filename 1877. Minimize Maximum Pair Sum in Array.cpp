#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sol = INT_MIN;
        for (int i = 0; i < n / 2; i++) {
            sol = max(sol, nums[i] + nums[n - i - 1]);
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
    cout << Solution().minPairSum(nums);
    return 0;
}