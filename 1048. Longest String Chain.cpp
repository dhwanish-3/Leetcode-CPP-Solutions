#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> map;
        int sol = 0;
        for(string word : words) {
            int longest = 0;
            for (int i = 0; i < word.length(); i++) {
                string str = word;
                str.erase(i, 1);
                longest = max(longest, map[str] + 1);
            }
            sol = max(sol, longest);
            map[word] = longest;
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cout << Solution().longestStrChain(words) << endl;
    return 0;
}