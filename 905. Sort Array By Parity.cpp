#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] % 2 == 0 && nums[r] % 2 != 0) {
                l++;
                r--;
            } else if (nums[l] % 2 == 0 && nums[r] % 2 == 0) {
                l++;
            } else if (nums[l] % 2 != 0 && nums[r] % 2 == 0) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            } else {
                r--;
            }
        }
        return nums;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    vector<int> sol = Solution().sortArrayByParity(nums);
    for (int& num : sol) {
        cout << num << " ";
    }
    return 0;
}