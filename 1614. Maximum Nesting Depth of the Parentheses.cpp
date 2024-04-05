#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int sol = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }
            sol = max(sol, count);
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().maxDepth(s);
    return 0;
}