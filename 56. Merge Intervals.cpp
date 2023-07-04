#include <bits/stdc++.h>
using namespace std;
// [[1,3],[2,5],[5,10],[11,16]]
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged(n);
        int count=0;
        int i=1;
        int maxTillNow=INT_MIN;
        while(i<n){
            int begin=i;
            merged[count].push_back(intervals[i-1][0]);
            maxTillNow=max(maxTillNow,intervals[i-1][1]);
            while(i<n && intervals[i][0]<=maxTillNow){
                maxTillNow=max(maxTillNow,intervals[i][1]);
                i++;
            }
            maxTillNow=max(maxTillNow,intervals[i-1][1]);
            merged[count].push_back(maxTillNow);
            count++;
            i++;
        }
        merged.resize(count);
        return merged;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    vector<vector<int>> sol=Solution().merge(v);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i][0]<<" "<<sol[i][1]<<endl;
    }
    return 0;
}