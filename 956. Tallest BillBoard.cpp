#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=rods[i];
        }
        vector<int> dp(sum+1,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            vector<int> prev(dp);
            for(int j=0;j<=sum-rods[i];j++){
                if(prev[j]<0) continue;
                dp[j]=max(dp[j],prev[j]);
                dp[j+rods[i]]=max(dp[j+rods[i]],prev[j]);
                dp[abs(j-rods[i])]=max(dp[abs(j-rods[i])],prev[j]+min(j,rods[i]));
            }
        }
        return dp[0];
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().tallestBillboard(v);
    
    return 0;
}