#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for (string s : word1) {
            s1 += s;
        }
        for (string s : word2) {
            s2 += s;
        }
        return s1 == s2;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> word1(n), word2(m);
    for (int i = 0; i < n; i++) {
        cin >> word1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> word2[i];
    }
    cout << Solution().arrayStringsAreEqual(word1, word2);
    return 0;
}