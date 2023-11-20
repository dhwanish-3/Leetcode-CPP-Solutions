#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sol = 0;
        for (int j = n - 1; j > 0; j--) {
            if (nums[j - 1] != nums[j]) {
                sol += n - j;
            }
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
    cout << Solution().reductionOperations(nums) << endl;
    return 0;
}