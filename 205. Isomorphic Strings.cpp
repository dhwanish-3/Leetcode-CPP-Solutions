#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        vector<int> sHash(128, 0), tHash(128, 0);
        for (int i = 0; i < len; i++) {
            if (sHash[s[i]] != tHash[t[i]]) {
                return false;
            }
            sHash[s[i]] = i + 1;
            tHash[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().isIsomorphic(s, t);
    return 0;
}