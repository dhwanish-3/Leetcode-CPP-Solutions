#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sol(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            vector<int> row(n);
            for (int j = 0; j < n; j++) {
                row[j] = matrix[j][i];
            }
            sol[i] = row;
        }
        return sol;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        vector<int> row(m);
        for (int j = 0; j < m; j++) {
            cin >> row[j];
        }
        matrix[i] = row;
    }
    vector<vector<int>> sol = Solution().transpose(matrix);
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}