#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> Chars;
        int longestSubstr=0;
        int start=0;
        for(int i=0;i<s.length();i++){
            if(Chars.find(s[i])!=Chars.end()){
                start=max(start,Chars[s[i]]+1);
            }
            longestSubstr=max(longestSubstr,i-start+1);
            Chars[s[i]]=i;
        }
        return longestSubstr;
    }
};

int main(){
    string s;
    cin>>s;
    cout<<Solution().lengthOfLongestSubstring(s);    
    return 0;
}