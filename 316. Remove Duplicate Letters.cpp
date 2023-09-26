#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int lastIndex[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        bool seen[26] = {false};
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            int cur = s[i] - 'a';
            if(seen[cur]) {
                continue;
            }
            while (!st.empty() && st.top() > s[i] && i < lastIndex[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[cur] = true;
        }
        string sol;
        while (!st.empty()) {
            sol += st.top();
            st.pop();
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().smallestSubsequence(s) << endl;
    return 0;
}