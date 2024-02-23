#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1), outDegree(n + 1);
        for (auto& t : trust) {
            outDegree[t[0]]++;
            inDegree[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> trust(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> trust[i][0] >> trust[i][1];
    }
    cout << Solution().findJudge(n, trust);
    return 0;
}