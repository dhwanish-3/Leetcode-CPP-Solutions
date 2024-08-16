#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long x = nums[0];
        for (int i = 1; i < n; i++) {
            x ^= nums[i];
        }
        long rightBit = (x) & ~(x - 1);
        vector<int> sol(2, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] & rightBit) {
                sol[0] ^= nums[i];
            } else {
                sol[1] ^= nums[i];
            }
        }
        return sol;
    }
};