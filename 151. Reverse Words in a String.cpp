#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        int start=0;
        int end=0;
        vector<string> strs;
        for(int i=1;i<len;i++){
            if(s[i]==' '){
                end=i;
                if(s.substr(start,end-start)!=" ")
                    strs.push_back(s.substr(start,end-start));
                start=i+1;
            }
        }
        if(s.substr(start)!=" ") strs.push_back(s.substr(start));
        sort(strs.begin(),strs.end());
        s="";
        for(int i=0;i<strs.size();i++){
            cout<<strs[i]<<endl;
        }
        return s;
    }
};

int main(){
    string s;
    getline(cin,s);
    cout<<Solution().reverseWords(s);
    return 0;
}