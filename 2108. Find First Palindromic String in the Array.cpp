#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (string& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cout << Solution().firstPalindrome(words);
    return 0;
}