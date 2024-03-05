#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) { 
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < meetings.size(); i++) {
            graph[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            graph[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }
        vector<int> sol;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, 0);
        q.emplace(0, firstPerson);
        vector<bool> visited(n, false);
        while (!q.empty()) {
            pair<int, int> meet = q.top();
            q.pop();
            if (visited[meet.second]) {
                continue;
            }
            visited[meet.second] = true;
            for (pair<int, int> meeter : graph[meet.second]) {
                if (!visited[meeter.first] && meet.first <= meeter.second) {
                    q.emplace(meeter.second, meeter.first);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                sol.push_back(i);
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    int firstPerson;
    cin >> firstPerson;
    vector<int> sol = Solution().findAllPeople(n, v, firstPerson);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}