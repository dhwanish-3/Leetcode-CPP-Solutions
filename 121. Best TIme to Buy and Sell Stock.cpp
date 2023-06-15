#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buyPrice=INT_MIN;
        for(int i=0;i<prices.size();i++){
            maxProfit=max(maxProfit,buyPrice+prices[i]);
            buyPrice=max(buyPrice,-prices[i]);
        }
        return maxProfit;
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