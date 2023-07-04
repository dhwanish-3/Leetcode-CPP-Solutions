#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().strStr(s,t);
    
    return 0;
}