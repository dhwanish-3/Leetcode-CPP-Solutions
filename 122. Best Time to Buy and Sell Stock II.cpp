#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxy=0;
        int buy=INT_MIN;
        for(int i=0;i<n;i++){
            maxy=max(maxy,buy+prices[i]);
            buy=max(buy,maxy-prices[i]);
        }
        return maxy;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().maxProfit(v);
    return 0;
}