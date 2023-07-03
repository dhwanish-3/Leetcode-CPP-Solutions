#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s ,string goal) {
        int len=s.length();
        if(len!=goal.length()) return false;
        if(len==0 || len==1) return false;
        int i=0,j=0;
        vector<int> hash1(26,0),hash2(26,0);
        for(int i=0;i<len;i++){
            hash1[s[i]-'a']++;
            hash2[goal[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i]) return false;
        }
        if(s==goal){
            for(int i=0;i<26;i++){
                if(hash1[i]>1) return true;
            }
        }
        vector<int> diff;
        for(int i=0;i<len;i++){
            if(s[i]!=goal[i]) diff.push_back(i);
        }
        return diff.size()==2 && s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]];
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().buddyStrings(s,t);
    return 0;
}