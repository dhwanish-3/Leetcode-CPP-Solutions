#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n && !(n&n-1));
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().isPowerOfTwo(n);    
    return 0;
}