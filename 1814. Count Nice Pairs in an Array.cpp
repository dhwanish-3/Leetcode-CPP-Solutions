#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
    int reverse(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int sol = 0;
        int n = nums.size();
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            int r = reverse(nums[i]);
            int cur = count[nums[i] - r];
            count[nums[i] - r] = cur + 1;
            sol = (sol + cur) % mod;
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
    cout << Solution().countNicePairs(nums) << endl;
    return 0;
}