#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int sol = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    height[j] = 0;
                } else {
                    height[j]++;
                }
            }
            vector<int> order_height = height;
            sort(order_height.begin(), order_height.end());
            for (int j = 0; j < m; j++) {
                sol = max(sol, order_height[j] * (m - j));
            }
        }
        return sol;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = s[j] - '0';
        }
    }
    cout << Solution().largestSubmatrix(matrix);
    return 0;
}