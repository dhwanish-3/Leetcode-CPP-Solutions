#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int nextGreater = n - 1;
            while (nextGreater > i) {
                if (nums[nextGreater] > nums[i]) {
                    break;
                }
                nextGreater--;
            }
            swap(nums[i], nums[nextGreater]);
            i++;
            int j = n - 1;
            while(i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        } else {
            reverse(nums.begin(), nums.end());
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    Solution().nextPermutation(nums);
    for (int& num : nums) {
        cout << num << " ";
    }
    return 0;
}