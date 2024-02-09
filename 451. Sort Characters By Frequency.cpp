#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<pair<int, char>> v;
        for (auto p : mp) {
            v.push_back({p.second, p.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string sol = "";
        for (auto p : v) {
            sol += string(p.first, p.second);
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().frequencySort(s);
    return 0;
}