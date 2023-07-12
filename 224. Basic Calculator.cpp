#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int len = s.length();
        int sign = 1;
        int num = 0;
        stack<int> stk{{sign}};
        for (int i=0 ; i<len; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '(') {
                stk.push(sign);
            } else if (s[i] == ')') {
                stk.pop();
            } else if (s[i] == '+' || s[i] == '-') {
                result += sign * num;
                sign = (s[i] == '+' ? 1: -1) * stk.top();
                num = 0;
            }
        }
        result += sign * num;
        return result;
    }
};

int main(){
    string s;
    getline(cin,s);
    cout<<Solution().calculate(s);
    return 0;
}