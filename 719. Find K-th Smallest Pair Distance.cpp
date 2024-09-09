#include <bits/stdc++.h>
using namespace std;

class Solution {
    int lessThanK(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        int sol = 0;
        for (int j = 1; j < n; j++) {
            while (i < n && nums[j] - nums[i] > k) {
                i++;
            }
            sol += j - i;
        }
        return sol;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = (l + r) / 2;
            if (lessThanK(nums, m) >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};