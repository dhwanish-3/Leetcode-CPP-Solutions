#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxElement = 0;
        for (int i = 0; i < n; i++) {
            maxElement = max(maxElement, nums[i]);
        }
        long long sol = 0;
        int freq = 0;
        for (int i = 0, j = 0; j < n; j++) {
            freq += nums[j] == maxElement ? 1 : 0;
            while (freq >= k) {
                freq -= nums[i] == maxElement ? 1 : 0;
                i++;
            }
            sol = sol + (long long)i;
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().countSubarrays(nums, k) << endl;
    return 0;
}