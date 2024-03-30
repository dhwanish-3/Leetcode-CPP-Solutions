#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        int n = nums.size();
        int sol = 0;
        int j = 0;
        int prod = 1;
        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            while (j <= i && prod >= k) {
                prod /= nums[j];
                j++;
            }
            sol += i - j + 1;
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
    cout << Solution().numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}