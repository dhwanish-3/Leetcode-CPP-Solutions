#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& sol, vector<int>& cur, vector<bool>& visit, int i) {
        if (i == graph.size() - 1) {
            cur.push_back(i);
            sol.push_back(cur);
            cur.pop_back();
            return;
        }
        visit[i] = true;
        cur.push_back(i);
        for (int j = 0; j < graph[i].size(); j++) {
            if (!visit[graph[i][j]])
                dfs(graph, sol, cur, visit, graph[i][j]);
        }
        visit[i] = false;
        cur.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> sol;
        vector<bool> visit(n, false);
        vector<int> cur;
        dfs(graph, sol, cur, visit, 0);
        return sol;
    }
};