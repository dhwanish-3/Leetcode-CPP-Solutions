#include <bits/stdc++.h>
using namespace std;

// Approach 1: Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> powerSet = vector<vector<int>>{{}};
        for (int i = 0; i < n; i++) {
            int size = powerSet.size();
            for (int j = 0; j < size; j++) {
                vector<int> temp = powerSet[j];
                temp.push_back(nums[i]);
                powerSet.push_back(temp);
            }
        }
        return powerSet;
    }
};

// Approach 2: Recursive
class Solution {
    void dfs(vector<int>& nums, int s, vector<int>& path, vector<vector<int>>& sol) {
        sol.push_back(path);
        for (int i = s; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, sol);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sol;
        vector<int> path;
        dfs(nums, 0, path, sol);
        return sol;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> powerSet = Solution().subsets(nums);
    for (int i = 0; i < powerSet.size(); i++) {
        for (int j = 0; j < powerSet[i].size(); j++) {
            cout << powerSet[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}