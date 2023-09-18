#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());
        vector<int> sol(k);
        for (int i = 0; i < k; i++) {
            sol[i] = mat[i][n];
        }
        return sol;
    }
};

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; i < n; j++) {
            cin >> mat[i][j];
        }
    }
    vector<int> sol = Solution().kWeakestRows(mat, k);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}