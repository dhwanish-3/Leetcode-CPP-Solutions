#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> hash(26, 0);
        int len = s.length();
        for (int i = 0; i < len; i++) {
            hash[s[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0) {
                count++;
            }
        }
        return count;
    }
};

int main(){
    string s;
    cin >> s;
    cout << Solution().minimizedStringLength(s);
    return 0;
}