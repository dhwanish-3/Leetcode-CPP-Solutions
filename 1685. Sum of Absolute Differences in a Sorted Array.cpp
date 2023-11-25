#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int left = 0;
        for (int i = 0; i < n; i++) {
            sol[i] = (nums[i] * i - left) + (sum - left - nums[i] * (n - i));
            left += nums[i];
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
    vector<int> sol = Solution().getSumAbsoluteDifferences(nums);
    for (int i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}