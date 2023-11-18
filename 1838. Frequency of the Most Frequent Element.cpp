#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sol = 1;
        long long sum = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while ((long)(j - i + 1) * nums[j] - sum > k) {
                sum -= nums[i];
                i++;
            }
            sol = max(sol, j - i + 1);
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().maxFrequency(nums, k);
    return 0;
}