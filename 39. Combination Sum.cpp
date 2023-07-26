#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int> candidates, int s, int target, vector<int>&& path, vector<vector<int>>& sol) {
        if (target < 0) return;
        if (target == 0) {
            sol.push_back(path);
            return;
        }
        for (int i = s; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                path.push_back(candidates[i]);
                dfs(candidates, i, target - candidates[i], move(path), sol);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        dfs(candidates, 0, target, {}, sol);
        return sol;
    }
};

int main(){
    int n, target;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> target;
    vector<vector<int>> sol = Solution().combinationSum(v, target);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}