#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector<int> sol;
        for (auto& pair : adj) {
            int key = pair.first;
            vector<int> value = pair.second;
            if (value.size() == 1) {
                sol.push_back(key);
                sol.push_back(value[0]);
                break;
            }
        }
        while (sol.size() < adjacentPairs.size() + 1) {
            int last = sol.back();
            int secondLast = sol[sol.size() - 2];
            for (auto& neighbour : adj[last]) {
                if (neighbour != secondLast) {
                    sol.push_back(neighbour);
                    break;
                }
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjacentPairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> adjacentPairs[i][0] >> adjacentPairs[i][1];
    }
    vector<int> sol = Solution().restoreArray(adjacentPairs);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}