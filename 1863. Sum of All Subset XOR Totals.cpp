#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xorSum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    xorSum ^= nums[j];
                }
            }
            sum += xorSum;
        }
        return sum;
    }
};

class Solution {
public:
    int subsetXORSum(vector<int>& nums, int i = 0, int num = 0) {
        if (i == nums.size()) {
            return num;
        }
        int include = subsetXORSum(nums, i + 1, num ^ nums[i]);
        int exclude = subsetXORSum(nums, i + 1, num);
        return include + exclude;
    }
};