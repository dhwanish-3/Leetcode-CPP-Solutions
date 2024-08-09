#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int n = nums.size();
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum %= k;
            if (sum < 0) sum += k;
            if (hash.find(sum) != hash.end()) {
                count += hash[sum];
            } 
            hash[sum] = hash[sum] + 1;
        }
        return count;
    }
};