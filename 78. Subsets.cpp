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
    vector<vector<int>> sol;
    void rec(vector<int>& nums, int i, vector<int>& cur) {
        sol.push_back(cur);
        for (int j = i; j < nums.size(); j++) {
            cur.push_back(nums[j]);
            rec(nums, j + 1, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        rec(nums, 0, cur);
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