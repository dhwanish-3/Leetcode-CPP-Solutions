#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sol = 0;
        for (int i = 1; i < points.size(); i++) {
            sol += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
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
    cout << Solution().minTimeToVisitAllPoints(points);
    return 0;
}