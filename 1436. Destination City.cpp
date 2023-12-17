#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> left;
        unordered_set<string> all;
        for (auto path : paths) {
            all.insert(path[0]);
            all.insert(path[1]);
        }
        for (auto path : paths) {
            all.erase(path[0]);
        }
        string sol;
        for (auto res : all) {
            sol = res;
        }
        return sol;
    }
};

int main() {
    int n;
    vector<vector<string>> paths(n, vector<string>(2));
    for (int i = 0; i < n; i++) {
        cin >> paths[i][0] >> paths[i][1];
    }
    cout << Solution().destCity(paths) << endl;
    return 0;
}