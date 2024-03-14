#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> hash;
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
        }
        string sol = "";
        for (int i = 0; i < order.length(); i++) {
            int count = hash[order[i]];
            for (int j = 0; j < count; j++) {
                sol += order[i];
            }
            hash[order[i]] = 0;
        }
        for (auto it : hash) {
            while (it.second > 0) {
                sol += it.first;
                it.second--;
            }
        }
        return sol;
    }
};

int main() {
    string order, s;
    cin >> order >> s;
    cout << Solution().customSortString(order, s);
    return 0;
}