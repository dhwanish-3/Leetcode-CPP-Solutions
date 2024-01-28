#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }
        vector<int> sol;
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                sol.push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 0) {
                sol.push_back(i);
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
    vector<int> sol = Solution().findErrorNums(nums);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}