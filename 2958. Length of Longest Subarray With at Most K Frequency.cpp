#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int sol = 0;
        unordered_map<int, int> hash;
        for (int i = 0, j = 0; j < n; j++) {
            hash[nums[j]]++;
            while (i <= j && hash[nums[j]] > k) {
                hash[nums[i]]--;
                i++;
            }
            sol = max(sol, j - i + 1);
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
    cout << Solution().maxSubarrayLength(nums, k) << endl;
    return 0;
}