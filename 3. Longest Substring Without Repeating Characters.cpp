#include <bits/stdc++.h>
using namespace std;

class Solution {
    map<char,int> Chars;
public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstr=0;
        int currSubstr=0;
        int i;
        for(i=0;i<s.length();i++){
            if(Chars.find(s[i])!=Chars.end()){
                if(longestSubstr<currSubstr){
                    longestSubstr=currSubstr;
                }
                else{
                    currSubstr=1;
                }
            }else{
                Chars[s[i]]=i;
                currSubstr++;
            } 
        }
        if(longestSubstr<currSubstr){
            longestSubstr=currSubstr;
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