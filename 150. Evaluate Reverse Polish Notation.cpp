#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();                            
                stk.pop();
                if (s == "+") stk.push(a + b);
                else if (s == "-") stk.push(b - a);
                else if (s == "*") stk.push(a * b);
                else stk.push(b / a);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().evalRPN(v);
    return 0;
}