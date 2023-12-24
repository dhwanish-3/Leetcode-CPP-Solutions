#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count(string s, char start) {
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (start == s[i]) {
                count++;
                start = start == '0'? '1':'0';
            } else {
                start = s[i];
            }
        }
        return count;
    }
public:
    int minOperations(string s) {
        int count1 = count(s, s[0]);
        int count2 = count(s, s[0] == '0' ? '1':'0') + 1;
        return min(count1, count2);
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().minOperations(s);
    return 0;
}