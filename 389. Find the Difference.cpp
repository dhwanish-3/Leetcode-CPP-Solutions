#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] < 0) {
                return (char)(i + 'a');
            }
        }
        return 'a';
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    cout << Solution().findTheDifference(s, t) << endl;
    return 0;
}