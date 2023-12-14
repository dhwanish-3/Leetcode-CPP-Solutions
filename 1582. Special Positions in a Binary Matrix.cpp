#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int sol = 0;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += mat[i][j];
            }
            row[i] = sum;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += mat[i][j];
            }
            col[j] = sum;
        }
        for (int i = 0; i < m; i++) {
            if (row[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1 && col[j] == 1) {
                        sol++;
                    }
                }
            }
        }
        return sol;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; i++) {
            cin >> mat[i][j];
        }
    }
    cout << Solution().numSpecial(mat);
    return 0;
}