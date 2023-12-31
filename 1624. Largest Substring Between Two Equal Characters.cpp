#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> start;
        int sol = -1;
        for (int i = 0; i < s.length(); i++) {
            if (start.find(s[i]) == start.end()) {
                start[s[i]] = i;
            } else {
                sol = max(sol, i - start[s[i]] - 1);
            }
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().maxLengthBetweenEqualCharacters(s);
    return 0;
}