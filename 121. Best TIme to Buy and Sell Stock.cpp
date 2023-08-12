#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        int maximumProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            buy = min(buy, prices[i]);
            profit = prices[i] - buy;
            maximumProfit = max(maximumProfit, profit);
        }
        return maximumProfit;
    }
};

int main(){
    int n,in;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<Solution().maxProfit(v);
    return 0;
}