#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string p, q;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!p.empty()) {
                    p.pop_back();
                }
            } else {
                p.push_back(s[i]);
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!q.empty()) {
                    q.pop_back();
                }
            } else {
                q.push_back(t[i]);
            }
        }
        return p == q;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().backspaceCompare(s, t) << endl;
    return 0;
}