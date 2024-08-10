#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dir = {0, 1, 0, -1, 0};
    void dfs(vector<vector<bool>>& mat, int i, int j) {
        int n = mat.size();
        if (mat[i][j]) return;
        mat[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k];
            int y = j + dir[k + 1];
            if (x >= 0 && y >= 0 && x < n && y < n) {
                if (!mat[x][y]) {
                    dfs(mat, x, y);
                }
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<bool>> mat(3 * n, vector(3 * n, false));
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < grid[i].length()) {
                if (grid[i][j] == '/') {
                    mat[3 * i][3 * j + 2] = true;
                    mat[3 * i + 1][3 * j + 1] = true;
                    mat[3 * i + 2][3 * j] = true;
                } else if (grid[i][j] == '\\') {
                    mat[3 * i][3 * j] = true;
                    mat[3 * i + 1][3 * j + 1] = true;
                    mat[3 * i + 2][3 * j + 2] = true;
                }
                j++;
            }
        }
        int sol = 0;
        for (int i = 0; i < 3 *n ; i++) {
            for (int j = 0; j < 3 * n; j++) {
                // cout << mat[i][j] << " ";
                if (!mat[i][j]) {
                    dfs(mat, i, j);
                    sol++;
                }
            } 
            // cout << endl;
        }
        return sol;
    }
};