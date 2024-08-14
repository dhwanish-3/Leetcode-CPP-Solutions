#include <bits/stdc++.h>
using namespace std;

class Solution {
    void rec(vector<int>& cnd, int x, vector<vector<int>>& sol, vector<int>& cur, int i) {
        if (x == 0) {
            sol.push_back(cur);
            return;
        }
        for (int j = i; j < cnd.size(); j++) {
            if (cnd[j] > x) break;
            if (j > i && cnd[j] == cnd[j - 1]) continue;
            cur.push_back(cnd[j]);
            rec(cnd, x - cnd[j], sol, cur, j + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& cnd, int x) {
        vector<vector<int>> sol;
        vector<int> cur;
        sort(cnd.begin(), cnd.end());
        rec(cnd, x, sol, cur, 0);
        return sol;
    }
};