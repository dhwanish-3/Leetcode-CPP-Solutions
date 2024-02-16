#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        long long maxPerimeter = -1;
        for (int i = n - 1; i >= 2; i--) {
            if (prefixSum[i] - 2 * nums[i] > 0) {
                maxPerimeter = max(maxPerimeter, prefixSum[i]);
            }
        }
        return maxPerimeter;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().largestPerimeter(nums);
    return 0;
}