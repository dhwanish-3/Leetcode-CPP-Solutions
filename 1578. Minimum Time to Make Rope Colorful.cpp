#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int sol = 0;
        for (int i = 1; i < n; i++) {
            if (neededTime[i] == neededTime[i - 1]) {
                sol += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return sol;
    }
};

int main() {
    string colors;
    cin >> colors;
    int n = colors.length();
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    cout << Solution().minCost(colors, time);
    return 0;
}