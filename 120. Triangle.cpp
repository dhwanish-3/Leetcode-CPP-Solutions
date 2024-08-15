#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                tri[i][j] = tri[i][j] + min(j < i ? tri[i - 1][j] : INT_MAX, j > 0 ? tri[i - 1][j - 1] : INT_MAX);
                cout << tri[i][j] << " ";
            }
            cout << endl;
        }
        return *min_element(tri[n - 1].begin(), tri[n - 1].end());
    }
};