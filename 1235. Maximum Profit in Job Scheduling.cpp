#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + (r - l + 1) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (jobs[l][1] <= jobs[i][0]) {
                dp[i] = max(dp[i - 1], dp[l] + jobs[i][2]);
            } else {
                dp[i] = max(dp[i - 1], jobs[i][2]);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), profit(n);
    for (int i = 0; i < n; i++) {
        cin >> startTime[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> endTime[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }
    cout << Solution().jobScheduling(startTime, endTime, profit);
    return 0;
}