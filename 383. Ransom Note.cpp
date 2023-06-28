#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i=0;i<ransomNote.length();i++){
            hash1[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.length();i++){
            hash2[magazine[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash1[i]>hash2[i]) return false;
        }
        return true;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().canConstruct(s,t);
    return 0;
}