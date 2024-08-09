#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> hash(26, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                hash[words[i][j] - 'a'][i]++;
            }
        }
        vector<string> sol;
        for (int i = 0; i < 26; i++) {
            int count = INT_MAX;
            for (int j = 0; j < n; j++) {
                count = min(count, hash[i][j]);
            }
            for (int k = 0; k < count; k++) {
                sol.push_back(string(1, i + 'a'));
            }
        }
        return sol;
    }
};