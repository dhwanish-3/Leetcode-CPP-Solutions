#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sol = 0;
        int n = garbage.size();
        int t = travel.size();
        for (auto g : garbage) {
            sol += g.length();
        }
        bool m = false;
        bool p = false;
        bool g = false;
        for (int i = t; i > 0; i--) {
            m = m || garbage[i].find("M") != string::npos;
            p = p || garbage[i].find("P") != string::npos;
            g = g || garbage[i].find("G") != string::npos;
            sol += travel[i - 1] * ((m ? 1 : 0) + (p ? 1 : 0) + (g ? 1 : 0));
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> garbage(n);
    for (int i = 0; i < n; i++) {
        cin >> garbage[i];
    }
    int m;
    cin >> m;
    vector<int> travel(m);
    for (int i = 0; i < m; i++) {
        cin >> travel[i];
    }
    cout << Solution().garbageCollection(garbage, travel) << endl;
    return 0;
}