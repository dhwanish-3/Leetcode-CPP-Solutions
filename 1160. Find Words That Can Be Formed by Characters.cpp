#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sol = 0;
        vector<int> chars_count(26, 0);
        for (char c : chars) {
            chars_count[c - 'a']++;
        }
        for (string word : words) {
            vector<int> word_count(26, 0);
            for (char c : word) {
                word_count[c - 'a']++;
            }
            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (word_count[i] > chars_count[i]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                sol += word.size();
            }
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
    string chars;
    cin >> chars;
    cout << Solution().countCharacters(words, chars);
    return 0;
}