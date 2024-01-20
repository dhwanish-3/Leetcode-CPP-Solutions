#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 != len2) {
            return false;
        }
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < len1; i++) {
            hash1[word1[i] - 'a']++;
            hash2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if ((hash1[i] == 0 && hash2[i] != 0) || (hash2[i] == 0 && hash1[i] != 0)) {
                return false;
            }
        }
        sort(hash1.begin(), hash1.end());
        sort(hash2.begin(), hash2.end());
        for (int i = 0; i < 26; i++) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    cout << Solution().closeStrings(word1, word2);
    return 0;
}