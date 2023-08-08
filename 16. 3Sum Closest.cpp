#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, dif = 0;
        int minDif = INT_MAX;
        int close;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                dif = abs(target - sum);
                if (dif == 0) {
                    return target;
                } else if (dif < abs(minDif)) {
                    minDif = dif;
                    close = sum;
                }
                if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return close;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    int target;
    cin >> target;
    cout << Solution().threeSumClosest(nums, target) << endl;
    return 0;
}