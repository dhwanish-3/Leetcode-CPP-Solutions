#include <bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int x,int y){
        if(x<y){
            int temp=x;
            x=y;
            y=temp;
        }
        while(y!=0){
            int num=y;
            y=x%y;
            x=num;
        }
        return x;
    }
 public:
  string gcdOfStrings(string str1, string str2) {
    int len1=str1.length();
    int len2=str2.length();
    int g=gcd(len1,len2);
    // string gcdString=s
  }
};

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<Solution().gcdOfStrings(s1,s2);
    
    return 0;
}