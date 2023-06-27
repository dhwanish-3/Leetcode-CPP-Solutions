#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        vector<int> hash(128,0);
        for(int i=0;i<t.length();i++){
            hash[t[i]]++;
        }
        int length=t.length();
        int minLength=INT_MAX;
        int l=0;
        int start=-1;
        for(int i=0;i<s.length();i++){
            if(--hash[s[i]]>=0){
                length--;
            }
            while(length==0){
                if(minLength>i-l+1){
                    start=l;
                    minLength=i-l+1;
                }
                if(++hash[s[l++]]>0){
                    length++;
                }
            }
        }
        return start==-1?"":s.substr(start,minLength);
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().minWindow(s,t);
    
    return 0;
}