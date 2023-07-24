#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int>& nums, vector<bool>&& used, vector<int>&& path, vector<vector<int>>& sol) {
        if (path.size() == nums.size()) {
            sol.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, move(used), move(path), sol);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<bool> used(nums.size(), false);
        dfs(nums, move(used), {}, sol);
        return sol;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n ;i++) {
        cin >> v[i];
    }
    vector<vector<int>> sol = Solution().permute(v);
    for (int i = 0; i < n; i++)
    return 0;
}