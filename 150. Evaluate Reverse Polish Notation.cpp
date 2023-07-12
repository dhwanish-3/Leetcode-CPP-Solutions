#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i=0 ; i<n; i++) {
            string s = tokens[i];
            if (s=="+" || s=="-" || s=="*" || s=="/") {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                int res = 0;
                if (s=="+") res = x + y;
                else if (s=="-") res = y - x;
                else if (s=="*") res = x * y;
                else if (s=="/") res = y / x;
                stk.push(res);
            } else {
                int num = stoi(s);
                stk.push(num);
            }
        }
        cout<<stk.size()<<endl;
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