#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), size = s.size();
        int i = 0, j = 0;
        for (i = 0; i < n; i++) {
            while (j < size && s[j] < g[i]) {
                j++;
            }
            if (j == size) {
                return i;
            }
            j++;
        }
        return i;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    cout << Solution().findContentChildren(g, s);
    return 0;
}