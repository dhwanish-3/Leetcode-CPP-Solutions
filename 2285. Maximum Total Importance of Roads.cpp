#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = make_pair(0, i);
        }
        for (auto it : roads) {
            nums[it[0]].first++;
            nums[it[1]].first++;
        }
        sort(nums.begin(), nums.end());
        vector<int> imp(n, 0);
        for (int i = 0; i < n; i++) {
            imp[nums[i].second] = i + 1;
        }
        long long sol = 0;
        for (auto it : roads) {
            sol += (long long)imp[it[0]] + imp[it[1]];
        }
        return sol;
    }
};