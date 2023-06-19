#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude=0;
        int currAltitude=0;
        for(int i=0;i<gain.size();i++){
            currAltitude+=gain[i];
            maxAltitude=max(maxAltitude,currAltitude);
        }
        return maxAltitude;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<Solution().largestAltitude(v);
    
    return 0;
}