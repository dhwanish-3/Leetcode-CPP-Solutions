#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> sol;
    void rec(vector<int>& cand, int i, int target, vector<int>& cur) {
        if (target < 0) return;
        if (target == 0) {
            sol.push_back(cur);
            return;
        }
        for (int j = i; j < cand.size(); j++) {
            cur.push_back(cand[j]);
            rec(cand, j, target - cand[j], cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        rec(candidates, 0, target, cur);
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