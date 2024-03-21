#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), compare);
        int sol = 1;
        vector<int> cur = points[0];
        for (int i = 1; i < n; i++) {
            if (cur[1] < points[i][0]) {
                cur = points[i];
                sol++;
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (2));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    cout << Solution().findMinArrowShots(v);
    return 0;
}