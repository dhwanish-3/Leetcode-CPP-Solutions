#include <bits/stdc++.h>
using namespace std;

class Solution {
    int binarySearch(vector<int>& nums, int num) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] >= num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] >= n) {
            return n;
        }
        for (int i = 0; i < n; i++) {
            int index = binarySearch(nums, i);
            if (n - index == i) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().specialArray(nums) << "\n";
    return 0;
}