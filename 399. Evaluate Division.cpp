#include <bits/stdc++.h>
using namespace std;

class Solution {
    double divide(unordered_map<string, unordered_map<string, double>> graph,const string& a, string& c, unordered_set<string>&& visited) {
        if (a == c) {
            return 1.0;
        }
        visited.insert(a);
        auto g = graph.at(a);
        for (auto it : g) {
            auto& b = it.first;
            auto& value = it.second;
            if (visited.count(b)) {
                continue;
            }
            double res = divide(graph, b, c, move(visited));
            if (res > 0) {
                return value * res;
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> sol;
        unordered_map<string, unordered_map<string, double>> graph;
        int n = equations.size();
        for (int i=0 ; i<n ; i++) {
            string& a = equations[i][0];
            string& b = equations[i][1];
            graph[a][b] = values[i];
            graph[b][a] = 1 / values[i];
        }
        for (auto query: queries) {
            string& a = query[0];
            string& c = query[1];
            if (!graph.count(a) || !graph.count(c)) {
                sol.push_back(-1);
            } else {
                sol.push_back(divide(graph, a, c, unordered_set<string> ()));
            }
        }
        return sol;
    }
};

int main(){
    
    
    return 0;
}