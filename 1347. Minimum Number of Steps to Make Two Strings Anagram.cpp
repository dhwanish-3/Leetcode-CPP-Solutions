#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sHash(26, 0);
        vector<int> tHash(26, 0);
        for (int i = 0; i < s.length(); i++) {
            sHash[s[i] - 'a']++;
            tHash[t[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (sHash[i] > tHash[i]) {
                count += (sHash[i] - tHash[i]);
            }
        }
        return count;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().minSteps(s, t);
    return 0;
}