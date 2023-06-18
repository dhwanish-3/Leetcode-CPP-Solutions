#include <bits/stdc++.h>
using namespace std;

class Solution {
    string modified(string& s1,string& s2){
        while(s1.find(s2)==0){
            s1=s1.substr(s2.length());
        }
        return s1;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length()<str2.length())
            return gcdOfStrings(str2,str1);
        if(str1.find(str2)==string::npos) return "";
        if(str2.empty()) return str1;
        return gcdOfStrings(str2,modified(str1,str2));
    }
};

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<Solution().gcdOfStrings(s1,s2);
    
    return 0;
}