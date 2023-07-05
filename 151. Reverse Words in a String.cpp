#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        int i=0;
        int j=0;
        stack<string> strs;
        while(i<len){
            while(i<len && s[i]==' ') i++;
            j=0;
            while(i<len && s[i]!=' '){
                i++;
                j++;
            }
            if(j!=0)
                strs.push(s.substr(i-j,j));
        }
        s="";
        while(!strs.empty()){
            s.append(strs.top());
            strs.pop();
            if(!strs.empty()) s.append(" ");
        }
        return s;
    }
};

int main(){
    string s;
    getline(cin,s);
    cout<<"string ->"<<Solution().reverseWords(s)<<"<-";
    return 0;
}