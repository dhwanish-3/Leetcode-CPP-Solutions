#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> dp{{-1,0}};
        sort(arr2.begin(),arr2.end());
        for(const int a:arr1){
            unordered_map<int,int> nextDp;
            for(const auto& pair:dp){
                int val=pair.first;
                int steps=pair.second;
                if(a>val){
                    nextDp[a]=min(nextDp.count(a)?nextDp[a]:INT_MAX,steps);
                }
                const auto it=upper_bound(arr2.begin(),arr2.end(),val);
                if(it!=arr2.cend()){
                    nextDp[*it]=min(nextDp.count(*it)?nextDp[*it]:INT_MAX,steps+1);
                }
            }
            if(nextDp.empty()) return -1;
            dp=move(nextDp);
        }
        int sol=INT_MAX;
        for (const auto& pair:dp){
            int steps=pair.second;
            sol=min(sol,steps);
        }
        return sol;
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> arr1(m);
    vector<int> arr2(n);
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    cout<<Solution().makeArrayIncreasing(arr1,arr2);
    return 0;
}