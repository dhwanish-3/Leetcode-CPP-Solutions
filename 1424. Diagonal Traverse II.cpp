#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxKey = 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                m[i + j].push_back(nums[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }
        vector<int> sol;
        for (int i = 0; i <= maxKey; i++) {
            for (int j = m[i].size() - 1; j >= 0; j--) {
                sol.push_back(m[i][j]);
            }
        }
        return sol;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; i < n; j++) {
            cin >> nums[i][j];
        }
    }
    vector<int> sol = Solution().findDiagonalOrder(nums);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}