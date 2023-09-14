class Solution {
    void dfs(unordered_map<string, multiset<string>>& graph, string cur, vector<string>& res) {
        while (!graph[cur].empty()) {
            string next = *graph[cur].begin();
            graph[cur].erase(graph[cur].begin());
            dfs(graph, next, res);
        }
        res.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> res;
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        dfs(graph, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};