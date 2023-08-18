#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x < 0 || x == m || y < 0 || y == n || mat[x][y] != -1) {
                    continue;
                }
                mat[x][y] = mat[i][j] + 1;
                q.emplace(x, y);
            }
        }
        return mat;
    }
};

int main() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> ans = Solution().updateMatrix(mat);
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}