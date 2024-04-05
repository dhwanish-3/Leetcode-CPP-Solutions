#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int sol = 0;
        unordered_map<int, int> hash;
        for (int i = 0, j = 0; j < n; ++j) {
            if (!hash[nums[j]]++) {
                k--;
            }
            while (k < 0) {
                if (!--hash[nums[i]]) {
                    k++;
                }
                i++;
            }
            sol += j - i + 1;
        }
        return sol;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().subarraysWithKDistinct(nums, k) << endl;
    return 0;
}