#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char pair(char c){
        switch(c){
            case ')': return  '(';
            case ']': return  '[';
            case '}': return  '{';
        }
        return ' ';
    }
    bool isOpening(char c){
        switch(c){
            case '(': return true;
            case '[': return true;
            case '{': return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(isOpening(s[i])){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }
                else if(stk.top()==pair(s[i])){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

int main(){
    string str;
    cin>>str;
    cout<<Solution().isValid(str);
    return 0;
}