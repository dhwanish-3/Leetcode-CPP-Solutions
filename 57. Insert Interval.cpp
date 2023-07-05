#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> sol;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            sol.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        sol.push_back(newInterval);
        while(i<n){
            sol.push_back(intervals[i]);
            i++;
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    vector<int> inter(2);
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1];
    cin>>inter[0]>>inter[1];
    vector<vector<int>> sol=Solution().insert(v,inter);
    for(int i=0;i<sol.size();i++) cout<<sol[i][0]<<" "<<sol[i][1]<<endl;
    return 0;
}