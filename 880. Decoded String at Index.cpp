#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BruteForce - Memory Limit Exceeded
    string decodeAtIndex(string s, int k) {
        long index = 0;
        string str;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                str += s[i];
                index++;
            } else {
                int n = s[i] - '0';
                string tmp = str;
                int len = str.length();
                index += (n - 1) * len;
                for (int j = 1; j < n; j++) {
                    str += tmp;
                }
                if (index >= k) {
                    return str.substr(k - 1, 1);
                }
            }
        }
        return "dhwanish";
    }

    string decodeAtIndex(string s, int k) {
        long curLen = 0;
        char ch;
        for (int i = 0; i < s.length(); i++) {
            ch = s[i];
            if (isdigit(ch)) {
                curLen *= (int)(ch - '0');
            } else {
                curLen++;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            ch = s[i];
            if (isdigit(ch)) {
                curLen /= (int)(ch - '0');
                k %= curLen;
            } else {
                if (k == 0 || k == curLen) {
                    return string(1, ch);
                }
                curLen--;
            }
        }
        return "dhwanish";
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << Solution().decodeAtIndex(s, k) << endl;
    return 0;
}