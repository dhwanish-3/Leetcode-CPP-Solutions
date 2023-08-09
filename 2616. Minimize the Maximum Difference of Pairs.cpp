#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (int i = 0; i < n - 1; i++) {
                if (mid >= (nums[i + 1] - nums[i])) {
                    count++;
                    i++;
                }
            }
            if (count >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    cout << Solution().minimizeMax(nums, p);
    return 0;
}