#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        string sol;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(sol.length());
            } else if (s[i] == ')') {
                int start = st.top();
                st.pop();
                reverse(sol.begin() + start, sol.end());
            } else {
                sol += s[i];
            }
        }
        return sol;
    }
};