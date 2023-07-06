#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length();
        int sol=0;
        int i=len-1;
        while(i>=0 && s[i]==' ') i--;
        while(i>=0 && s[i]!=' '){
            sol++;
            i--;
        }
        return sol;
    }
};

int main(){
    string s;
    getline(cin,s);
    cout<<Solution().lengthOfLastWord(s);
    return 0;
}