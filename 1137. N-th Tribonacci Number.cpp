#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n<2) return n;
        if(n==2) return 1;
        vector<int> tri(n+2);
        tri[0]=0;
        tri[1]=1;
        tri[2]=1;
        for(int i=3;i<n+1;i++){
            tri[i]=tri[i-1]+tri[i-2]+tri[i-3];
        }
        return tri[n];
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().tribonacci(n);
    
    return 0;
}