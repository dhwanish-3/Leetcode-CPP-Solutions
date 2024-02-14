#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive, negative;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negative.push_back(nums[i]);
            } else {
                positive.push_back(nums[i]);
            }
        }
        int j = 0, k = 0;
        vector<int> sol(n, 0);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sol[i] = positive[j];
                j++;
            } else {
                sol[i] = negative[k];
                k++;
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
    vector<int> sol = Solution().rearrangeArray(nums);
    for (int i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}