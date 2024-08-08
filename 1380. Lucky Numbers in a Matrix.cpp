#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, INT_MAX), col(n, INT_MIN), sol;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] = min(row[i], matrix[i][j]);
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == col[j]) {
                    sol.push_back(row[i]);
                }
            }
        }
        return sol;
    }
};