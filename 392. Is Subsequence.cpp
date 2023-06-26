#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        int j=0;
        for(int i=0;i<t.length();i++){
            if(t[i]==s[j]) j++;
            if(j==s.length()) return true;
        }
        return false;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().isSubsequence(s,t);
    return 0;
}