#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int n=height.size();
        vector<int> maxFromLeft(n);
        vector<int> maxFromRight(n);
        maxFromLeft[0]=height[0];
        for(int i=1;i<n;i++){
            maxFromLeft[i]=max(height[i],maxFromLeft[i-1]);
        }
        maxFromRight[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxFromRight[i]=max(height[i],maxFromRight[i+1]);
        }
        for(int i=0;i<n;i++){
            cout<<maxFromLeft[i]<<" "<<maxFromRight[i]<<endl;
        }
        for(int i=0;i<n;i++){
            water+=(min(maxFromLeft[i],maxFromRight[i])-height[i]);
        }
        return water;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().trap(v);
    return 0;
}