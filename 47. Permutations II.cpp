#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> sol;
    void rec(vector<int> nums, int i, int j) {
        if (i == j - 1) {
            sol.push_back(nums);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            rec(nums, i + 1, j);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        rec(nums, 0, nums.size());
        return sol;
    }
};