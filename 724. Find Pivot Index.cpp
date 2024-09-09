#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            left[i] = left[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (left[i] == left[n] - left[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};