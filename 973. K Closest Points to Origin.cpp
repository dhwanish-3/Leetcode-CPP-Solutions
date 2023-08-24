#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
        for (auto point : points) {
            q.emplace((point[0] * point[0]) + (point[1] * point[1]), point);
        }
        int i = 0;
        vector<vector<int>> sol(k);
        while (i < k) {
            sol[i] = q.top().second;
            q.pop();
            i++;
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    vector<vector<int>> sol = Solution().kClosest(points, k);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i][0] << " " << sol[i][1] << endl;
    }
    return 0;
}