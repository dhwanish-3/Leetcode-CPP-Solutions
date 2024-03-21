#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, sol = 0;
        unordered_map<int, int> hash{{0, -1}};
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (hash.count(sum)) {
                sol = max(sol, i - hash[sum]);
            } else {
                hash[sum] = i;
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().findMaxLength(nums);
    return 0;
}