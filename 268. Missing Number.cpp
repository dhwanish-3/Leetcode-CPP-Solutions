#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        bool hash[n + 1];
        for (int i = 0; i < n + 1; i++) {
            hash[i] = false;
        }
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = true;
        }
        for (int i = 0; i < n + 1; i++) {
            if (!hash[i]) {
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
    cout << Solution().missingNumber(nums);
    return 0;
}