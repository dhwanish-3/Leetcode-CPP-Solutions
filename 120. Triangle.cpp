#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        int sol = INT_MAX;
        for (int i = 0; i < triangle[n - 1].size(); i++) {
            sol = min(sol, triangle[n - 1][i]);
        }
        return sol;
    }
};