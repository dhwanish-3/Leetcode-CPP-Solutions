#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sHash(128,0);
        vector<int> tHash(128,0);
        for(int i=0;i<s.size();i++){
            if(sHash[s[i]]!=tHash[t[i]]) return false;
            sHash[s[i]]=i+1;
            tHash[t[i]]=i+1;
        }
        return true;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().isIsomorphic(s,t);
    
    return 0;
}