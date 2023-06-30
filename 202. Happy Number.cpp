#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        map<int,bool> hash;
        while(n!=1){
            int num=n;
            n=0;
            while(num){
                int rem=num%10;
                num/=10;
                n+=(rem*rem);
            }
            if(hash.find(n)!=hash.end()) return false;
            hash[n]=true;
        }
        return true;
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().isHappy(n);
    return 0;
}