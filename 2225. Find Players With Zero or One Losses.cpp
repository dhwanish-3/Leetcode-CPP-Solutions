#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> hash;
        int n = matches.size();
        for (int i = 0; i < n; i++) {
            hash[matches[i][1]]++;
        }
        vector<vector<int>> sol(2);
        for (int i = 0; i < n; i++) {
            if (hash[matches[i][0]] == 0) {
                sol[0].push_back(matches[i][0]);
                hash[matches[i][0]] = -1;
            } else if (hash[matches[i][0]] == 1) {
                sol[1].push_back(matches[i][0]);
                hash[matches[i][0]] = -1;
            }
            if (hash[matches[i][1]] == 1) {
                sol[1].push_back(matches[i][1]);
                hash[matches[i][1]] = -1;
            } 
        }
        sort(sol[0].begin(), sol[0].end());
        sort(sol[1].begin(), sol[1].end());
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matches(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> matches[i][0] >> matches[i][1];
    }
    vector<vector<int>> sol = Solution().findWinners(matches);
    for (int i = 0; i < sol[0].size(); i++) {
        cout << sol[0][i] << " ";
    }
    return 0;
}