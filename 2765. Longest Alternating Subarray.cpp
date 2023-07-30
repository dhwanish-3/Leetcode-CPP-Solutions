#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int sol = 1;
        int dp = 1;
        for (int i = 1; i < nums.size(); i++) {
            int targetDiff = dp % 2 == 0 ? -1 : 1;
            if (nums[i] - nums[i - 1] == targetDiff) {
                dp++;
            } else if (nums[i] - nums[i - 1] == 1) {
                dp = 2;
            } else {
                dp = 1;
            }
            sol = max(sol, dp);
        }
        return sol == 1 ? -1 : sol;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    cout << Solution().alternatingSubarray(nums) << endl;
    return 0;
}