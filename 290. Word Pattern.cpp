#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len=s.length();
        int n=pattern.length();
        int start=0;
        int end=0;
        vector<string> m1(30);
        map<string,char> m2;
        int count=0;
        s.append(" ");
        for(int i=0;i<len+1;i++){
            if(count>=n) return false;
            if(s[i]==' '){
                string find=m1[pattern[count]-'a'];
                end=i;
                auto it=m2.find(s.substr(start,end-start));
                if(it==m2.end() && find.empty()){
                    m2[s.substr(start,end-start)]=pattern[count];
                    m1[pattern[count]-'a']=s.substr(start,end-start);
                }else if(it==m2.end() || find.empty()){
                    return false;
                }else{
                    if(it->second!=pattern[count] || find!=s.substr(start,end-start)){
                        return false;
                    }
                }
                start=i+1;
                count++;
            }
        }
        return count==n;
    }
};

int main(){
    string pattern,s;
    getline(cin,pattern);
    getline(cin,s);
    cout<<Solution().wordPattern(pattern,s);
    return 0;
}