#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sol(m, vector<int>(n));
        vector<int> onesRow(m, 0);
        vector<int> zeroesRow(m, 0);
        vector<int> onesCol(n, 0);
        vector<int> zeroesCol(n, 0);
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            onesRow[i] = sum;
            zeroesRow[i] = n - sum;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            onesCol[j] = sum;
            zeroesCol[j] = m - sum;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sol[i][j] = onesRow[i] + onesCol[j] - zeroesRow[i] - zeroesCol[j];
            }
        }
        return sol;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> sol = Solution().onesMinusZeros(grid);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}