#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int n, int k, int s, vector<int>&& path, vector<vector<int>>& sol) {
        if (path.size() == k) {
            sol.push_back(path);
            return;
        }
        for (int i = s; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, move(path), sol);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        dfs(n, k, 1, {}, sol);
        return sol;
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> sol = Solution().combine(n, k);
    return 0;
}