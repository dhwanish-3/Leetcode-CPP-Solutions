#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calculateTime(int course, vector<int>& time, vector<vector<int>>& graph, vector<int>& dp) {
        if (dp[course] != -1) {
            return dp[course];
        }
        if (graph[course].empty()) {
            dp[course] = time[course];
            return dp[course];
        }
        int maxTime = 0;
        for (int pre : graph[course]) {
            maxTime = max(maxTime, calculateTime(pre, time, graph, dp));
        }
        dp[course] = maxTime + time[course];
        return dp[course];
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n);
        for (auto relation : relations) {
            graph[relation[0] - 1].push_back(relation[1] - 1);
        }
        vector<int> dp(n, -1);
        int overallMinTime = 0;
        for (int i = 0; i < n; i++) {
            overallMinTime = max(overallMinTime, calculateTime(i,time, graph, dp));
        }
        return overallMinTime;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> relations = {{1, 2}, {2, 3}, {3, 4}};
    vector<int> time = {1, 2, 3, 4};
    cout << Solution().minimumTime(n, relations, time) << endl;
    return 0;
}