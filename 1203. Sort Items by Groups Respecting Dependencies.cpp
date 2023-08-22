#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& indegree, int n, int cur, vector<int>& sol) {
        if (cur < n) {
            sol.push_back(cur);
        }
        indegree[cur] = -1; // marking as visited
        for (auto next : graph[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                dfs(graph, indegree, n, next, sol);
            }
        }
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> graph(n + m);
        vector<int> indegree(n + m, 0);
        for (int i = 0; i < group.size(); i++) {
            if (group[i] != -1) {
                graph[n + group[i]].push_back(i);
                indegree[i]++;
            }
        }
        for (int i = 0; i < beforeItems.size(); i++) {
            for (int e : beforeItems[i]) {
                int a = group[e] == -1 ? e : n + group[e];
                int b = group[i] == -1 ? i : n + group[i];
                if (a == b) { // same group, ingroup order
                    graph[e].push_back(i);
                    indegree[i]++;
                } else { // outgroup order
                    graph[a].push_back(b);
                    indegree[b]++;
                }
            }
        }
        vector<int> sol;
        for (int i = 0; i < n + m; i++) {
            if (indegree[i] == 0) {
                dfs(graph, indegree, n, i, sol);
            }
        }
        return sol.size() == n ? sol : vector<int>{};
    }
};

int main() {
    int n = 8, m = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
    Solution sol;
    vector<int> ans = sol.sortItems(n, m, group, beforeItems);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}