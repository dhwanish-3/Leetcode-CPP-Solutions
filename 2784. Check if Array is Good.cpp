#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ) {
            if (nums[i] >= n) {
                return false;
            }
            if (nums[nums[i] - 1] == nums[i]) {
                ++i;
            } else {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1 && i != n - 1) {
                return false;
            }
        }
        return n >= 2 && nums.back() == n - 1 && nums[n - 2] == n - 1;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    cout << Solution().isGood(nums) << endl;
    return 0;
}