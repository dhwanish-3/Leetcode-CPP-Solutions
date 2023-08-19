#include <bits/stdc++.h>
using namespace std;

// Approach 1: Expand Around Center
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        if (s.length() == 2) {
            return s[0] == s[1] ? s : s.substr(0, 1);
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > end - start + 1) {
                start = l + 1;
                end = r - 1;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > end - start + 1) {
                start = l + 1;
                end = r - 1;
            }
        }
        if (start == end) {
            return s.substr(0, 1);
        } else {
            return s.substr(start, end - start + 1);
        }
    }
};

// Approach 2: DP - slow
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int start = 0, end = 0;
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i + 1 < len && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                end = i + 1;
            }
        }
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 2; j < len; j++) {
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (j - i > end - start) {
                        start = i;
                        end = j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// Approach 3: Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$#";
        for (int i = 0; i < s.length(); i++) {
            t += s[i];
            t += "#";
        }
        vector<int> p(t.length(), 0);
        int id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 1; i < t.length(); i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) {
                p[i]++;
            }
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}