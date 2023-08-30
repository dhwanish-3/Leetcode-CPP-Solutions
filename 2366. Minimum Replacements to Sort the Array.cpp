#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n - 1];
        long long sol = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > last) {
                int times = nums[i] / last;
                if (nums[i] % last) {
                    times++;
                }
                last = nums[i] / times;
                sol += times - 1;
            } else {
                last = nums[i];
            }
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
    cout << Solution().minimumReplacement(nums) << endl;
    return 0;
}