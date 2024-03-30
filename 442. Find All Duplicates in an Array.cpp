#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol;
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (nums[val - 1] < 0) {
                sol.push_back(val);
            } else {
                nums[val - 1] = -1 * nums[val - 1];
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
    vector<int> sol = Solution().findDuplicates(nums);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}