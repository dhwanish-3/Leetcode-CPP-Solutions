#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber == 0) {
            return "";
        }
        string s;
        int n = columnNumber;
        while(n != 0){
            s.insert(s.begin(), 'A' + (n - 1) % 26);
            n = (n - 1) / 26;
        }
        return s;
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().convertToTitle(n);
    return 0;
}