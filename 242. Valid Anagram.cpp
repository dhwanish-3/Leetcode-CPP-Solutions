#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash1(26);
        vector<int> hash2(26);
        for(int i=0;i<s.length();i++){
            hash1[s[i]]++;
            hash2[t[i]]++;
        }
        for(int i=0;i<hash1.size();i++){
            if(hash1[i]!=hash2[i]) return false;
        }
        return true;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().isAnagram(s,t);
    
    return 0;
}