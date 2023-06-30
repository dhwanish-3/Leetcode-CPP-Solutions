#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len=s.length();
        int start=0;
        int end=0;
        vector<string> m1(26,"dhwanish");
        map<string,char> m2;
        int count=0;
        for(int i=0;i<len;i++){
            if(i==len-1){
                string find=m1[pattern[count]-'a'];
                if(find=="dhwanish"){
                    cout<<s.substr(start);
                    m1[pattern[count]-'a']=s.substr(start);
                    count++;
                }else if(find!=s.substr(start,end-start)){
                    return false;
                }
            }
            else if(s[i]==' '){
                string find=m1[pattern[count]-'a'];
                end=i;
                cout<<s.substr(start,end-start)<<endl;
                if(find=="dhwanish"){
                    m1[pattern[count]-'a']=s.substr(start,end-start);
                }else if(find!=s.substr(start,end-start)){
                    return false;
                }
                start=i+1;
                count++;
            }
        }
        cout<<count<<endl;
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