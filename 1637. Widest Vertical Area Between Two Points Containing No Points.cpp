#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int sol = 0;
        int n = points.size();
        for (int i = 1; i < n; i++) {
            sol = max(sol, points[i][0] - points[i - 1][0]);
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    cout << Solution().maxWidthOfVerticalArea(points);
    return 0;
}