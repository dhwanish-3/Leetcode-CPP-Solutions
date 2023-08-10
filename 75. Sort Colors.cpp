#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m = 0;
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            } else if (nums[m] == 2) {
                swap(nums[m], nums[r]);
                r--;
            } else {
                m++;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution().sortColors(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}