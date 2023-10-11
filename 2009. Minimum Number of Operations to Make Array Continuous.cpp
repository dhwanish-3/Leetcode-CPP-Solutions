#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int sol = n;
        int j = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        for (int i = 0; i < m; i++) {
            while (j < m && nums[j] < nums[i] + n) {
                j++;
            }
            sol = min(sol, n - j + i);
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    cout << Solution().minOperations(nums) << endl;
    return 0;
}