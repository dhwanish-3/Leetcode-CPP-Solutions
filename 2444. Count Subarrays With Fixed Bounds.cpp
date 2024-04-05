#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long sol = 0;
        int jbad = -1, jmin = -1, jmax = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                jbad = i;
            }
            if (minK == nums[i]) {
                jmin = i;
            }
            if (maxK == nums[i]) {
                jmax = i;
            }
            sol += (long long)max(0, min(jmin, jmax) - jbad);
        }
        return sol;
    }
};

int main() {
    int n, minK, maxK;
    cin >> n >> minK >> maxK;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().countSubarrays(nums, minK, maxK) << endl;
    return 0;
}