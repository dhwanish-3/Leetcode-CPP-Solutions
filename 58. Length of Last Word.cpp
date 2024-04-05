#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int i = len - 1, sol = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            sol++;
            i--;
        }
        return sol;
    }
};

int main() {
    string s;
    getline(cin, s);
    cout << Solution().lengthOfLastWord(s) << endl;
    return 0;
}