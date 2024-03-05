#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;
        int l = 0, r = n - 1;
        vector<int> sol(n, 0);
        for (;k >= 0; k--) {
            if (abs(nums[l]) >= abs(nums[r])) {
                sol[k] = nums[l] * nums[l];
                l++;
            } else {
                sol[k] = nums[r] * nums[r];
                r--;
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> sol = Solution().sortedSquares(nums);
    for (int i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}