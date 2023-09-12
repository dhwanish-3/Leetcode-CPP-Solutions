#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> hash;
        unordered_set<int> freq;
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
        }
        int deletions = 0;
        for (auto it : hash) {
            while (it.second > 0 && freq.count(it.second)) {
                it.second--;
                deletions++;
            }
            freq.insert(it.second);
        }
        return deletions;
    }
};

int main() {
    string s = "ceabaacb";
    cout << Solution().minDeletions(s) << endl;
    return 0;
}