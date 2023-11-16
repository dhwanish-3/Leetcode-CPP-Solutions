#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> vowelsInString;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (vowels.find(s[i]) != string::npos) {
                vowelsInString.push_back(s[i]);
            }
        }
        sort(vowelsInString.begin(), vowelsInString.end(), greater<char>());
        string sol;
        for (int i = 0; i < n; i++) {
            if (vowels.find(s[i]) != string::npos) {
                sol += vowelsInString.back();
                vowelsInString.pop_back();
            } else {
                sol += s[i];
            }
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().sortVowels(s) << endl;
    return 0;
}