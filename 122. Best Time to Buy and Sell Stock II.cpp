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
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buyPrice = 0;
        int sellPrice = 0;
        int Profit = 0;
        int i = 0;
        while (i < n - 1) {
            while (i < n - 1 && prices[i + 1] <= prices[i]) {
                i++;
            }
            buyPrice = prices[i];
            while (i < n - 1 && prices[i + 1] > prices[i]) {
                i++;
            }
            sellPrice = prices[i];
            Profit += (sellPrice - buyPrice);
        }
        return Profit;
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