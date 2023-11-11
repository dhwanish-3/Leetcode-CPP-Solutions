#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        int sol = 0;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int len = j - i;
            sol = (sol + (len * (len + 1) / 2) % mod) % mod;
            i = j;
        }
        return sol;
    }
};

int main() {
    string s;
    cin >> s;

    cout << Solution().countHomogenous(s) << endl;
    return 0;
}