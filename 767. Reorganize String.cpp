#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int len = s.length();
        vector<int> hash(26, 0);
        for (int i = 0; i < len; i++) {
            hash[s[i] - 'a']++;
        }
        int maxFreq = 0;
        char letter = 'a';
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                letter = (char)i + 'a';
            }
        }
        if (maxFreq > (len + 1) / 2) {
            return "";
        }
        string sol;
        sol.resize(len);
        int index = 0;
        while (hash[letter - 'a'] > 0) {
            sol[index] = letter;
            index += 2;
            hash[letter - 'a']--;
        }
        for (int i = 0; i < hash.size(); i++) {
            while (hash[i] > 0) {
                if (index >= len) {
                    index = 1;
                }
                sol[index] = (char)i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().reorganizeString(s);
    return 0;
}