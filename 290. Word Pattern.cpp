#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len=s.length();
        int start=0;
        int end=0;
        map<char,string> m1;
        map<string,char> m2;
        int count=0;
        for(int i=1;i<len;i++){
            if(i==len-1) cout<<s.substr(start);
            if(s[i]==' '){
                end=i;
                cout<<s.substr(start,end-start+1)<<endl;
                m1[pattern[count]]=s.substr(start,end-start+1);
                start=i+1;
                count++;
            }
        }
        return true;
    }
};

int main(){
    string pattern,s;
    getline(cin,pattern);
    getline(cin,s);
    cout<<Solution().wordPattern(pattern,s);
    
    return 0;
}