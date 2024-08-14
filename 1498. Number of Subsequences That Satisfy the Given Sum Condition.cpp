#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> powers(n, 1);
        for (int i = 1; i < n; i++) {
            powers[i] = powers[i - 1] * 2 % mod;
        }
        int l = 0, r = n - 1;
        int sol = 0;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                sol = (sol + powers[r - l]) % mod;
                l++;
            }
        }
        return sol;
    }
};

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().numSubseq(nums, x);
    return 0;
}