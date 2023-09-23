#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        int target = total - x;
        if (target == 0) {
            return nums.size();
        } else if (target < 0) {
            return -1;
        }
        int cur = 0;
        int len = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            cur += nums[r];
            while (cur > target) {
                cur -= nums[l];
                l++;
            }
            if (cur == target) {
                len = max(len, r - l + 1);
            }
        }
        return len == 0 ? -1 : nums.size() - len;
    }
};

int main() {
    int n, x;
    cin >> n >> x;  
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().minOperations(nums, x) << endl;
    return 0;
}