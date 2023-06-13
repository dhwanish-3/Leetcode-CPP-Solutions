#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10 && x>=0) return true;
        long rev=0;
        int num=x;
        while(num!=0){
            rev=rev*10+(num%10);
            num/=10;
        }
        cout<<rev<<endl;
        return x==rev;
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().isPalindrome(n);
    return 0;
}