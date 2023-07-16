#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sol;
        int carry = 0;
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        while (len1 >= 0 || len2 >= 0 || carry) {
            if (len1 >= 0) {
                carry += a[len1] -'0';
                len1--;
            }
            if (len2 >= 0) {
                carry += b[len2] - '0';
                len2--;
            }
            sol += carry % 2 + '0';
            carry /= 2;
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    cout<<Solution().addBinary(s,t);
    return 0;
}