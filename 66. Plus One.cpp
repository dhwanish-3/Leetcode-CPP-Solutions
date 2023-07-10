#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9) {
            digits[n-1] += 1;
            return digits;
        }
        int i = n-1;
        int carry = 1;
        int rem = 0;
        while(i >= 0) {
            if(digits[i] + carry > 9) {
                carry = 1;
                rem = 0;
            } else{
                digits[i] += 1;
                break;
            }
            digits[i] = rem;
            i--;
        }
        if( i < 0 ) {
            vector<int> sol(n+1, 0);
            sol[0] = 1;
            return sol;
        }
        return digits;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n ; i++) cin>>v[i];
    vector<int> sol = Solution().plusOne(v);
    for(int i=0; i<sol.size(); i++) cout<<sol[i]<<" ";
    return 0;
}