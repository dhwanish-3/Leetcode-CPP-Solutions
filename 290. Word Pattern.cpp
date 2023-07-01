#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len=s.length();
        int n=pattern.length();
        int start=0;
        int end=0;
        vector<string> m1(26,"dhwanish");
        map<string,char> m2;
        int count=0;
        for(int i=0;i<len && count<n;i++){
            if(i==len-1){
                string find=m1[pattern[count]-'a'];
                auto it=m2.find(s.substr(start));
                cout<<s.substr(start);
                if(it==m2.end() && find=="dhwanish"){
                    // m1[pattern[count]-'a']=s.substr(start);
                    // m2[s.substr(start)]=pattern[count];
                }else if(it->second!=pattern[count] || find!=s.substr(start)){
                    return false;
                }
                count++;
            }
            else if(s[i]==' '){
                string find=m1[pattern[count]-'a'];
                end=i;
                auto it=m2.find(s.substr(start,end-start));
                cout<<s.substr(start,end-start)<<endl;
                if(it==m2.end() && find=="dhwanish"){
                    m2[s.substr(start,end-start)]=pattern[count];
                    m1[pattern[count]-'a']=s.substr(start,end-start);
                }else if(it->second!=pattern[count] || find!=s.substr(start,end-start)){
                    return false;
                }
                start=i+1;
                count++;
            }
        }
        cout<<" count is : "<<count<<endl;
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