#include <bits/stdc++.h>
using namespace std;

class Solution {
    // DP
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> buy(n+1,INT_MIN);
        vector<int> sell(n+1,0);
        for(int i=1;i<n+1;i++){
            buy[i]=max(buy[i-1],sell[i-1]-prices[i-1]-fee);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i-1]);
        }
        return max(buy[n],sell[n]);
    }
};

int main(){
    int n,fee;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>fee;
    cout<<Solution().maxProfit(v,fee);
    return 0;
}