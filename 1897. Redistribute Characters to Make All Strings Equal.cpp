#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> hash(26, 0);
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                hash[words[i][j] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] % n != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cout << Solution().makeEqual(words);
    return 0;
}