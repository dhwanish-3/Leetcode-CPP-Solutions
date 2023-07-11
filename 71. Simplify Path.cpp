#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        vector<string> stk;
        for(int i=1 ;i<len ; i++) {
            int begin = i;
            while(i<len && path[i] != '/') {
                i++;
            }
            string s = path.substr(begin,i-begin);
            cout<<"->"<<s<<"<-"<<endl;
            if(i-begin == 0 || s == "."){
                continue;
            }
            if(s == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            }else{
                stk.push_back(s);
            }
        }
        string sol;
        for(int i=0 ; i<stk.size(); i++) {
            sol += "/" + stk[i];
        }
        return stk.empty() ? "/" : sol;
    }
};

int main(){
    string s;
    cin>>s;
    cout<<Solution().simplifyPath(s);
    return 0;
}