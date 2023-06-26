#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    string s;
    getline(cin,s);
    cout<<Solution().isPalindrome(s);
    return 0;
}