#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if ((nums[l] == nums[mid]) && (nums[r] == nums[mid])) {
                l++;
                r--;
            } else if (nums[l] <= nums[mid]) {
                if ((nums[l] <= target) && (nums[mid] > target)) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if ((nums[mid] < target) && (nums[r] >= target)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().search(nums, target);
    return 0;
}