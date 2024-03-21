#include <bits/stdc++.h>
using namespace std;

class Solution {
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }
        int n = nums.size();
        int i = 0, sum = 0;
        int count = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while (i < n && sum > goal) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main() {
    int n, goal;
    cin >> n >> goal;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().numSubarraysWithSum(nums, goal);
    return 0;
}