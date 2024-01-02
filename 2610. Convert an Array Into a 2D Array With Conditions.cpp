#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> hash(n + 1);
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = make_pair(1 + hash[nums[i]].first, nums[i]);
        }
        sort(hash.begin(), hash.end(), greater<pair<int, int>>());
        vector<vector<int>> sol(hash[0].first);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < hash[i].first; j++) {
                sol[j].push_back(hash[i].second);
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
    vector<vector<int>> sol = Solution().findMatrix(nums);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}