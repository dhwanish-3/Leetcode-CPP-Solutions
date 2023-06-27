#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, pair<int, int>>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // int count=0;
        // int n1=nums1.size(),n2=nums2.size();
        // int one=0,two=0;
        // vector<vector<int>> sol;
        // while(count<k && one<n1 && two<n2){
        //     sol.push_back({nums1[one],nums2[two]});
        //     if(one+1<n1 && two+1<n2 && nums1[one+1]<=nums2[two+1]){
        //         one++;
        //     }else if(two+1<n2){
        //         two++;
        //     }
        //     count++;
        // }
        // while(count<k && one<n1){
        //     sol.push_back({nums1[one],nums2[two]});
        //     one++;
        // }
        // while(count<k && two<n2){
        //     sol.push_back({nums1[one],nums2[two]});
        //     two++;
        // }
        // return sol;
        vector<vector<int>> sol;
        int n1=nums1.size(),n2=nums2.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i=0;i<k && i<n1;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(k>0 && !pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int first=curr.second.first;
            int second=curr.second.second;
            sol.push_back({nums1[first],nums2[second]});
            if(second+1<n2) {
                pq.push({nums1[first]+nums2[second+1],{first,second+1}});
            }        
            k--;
        }
        return sol;
    }
};

int main(){
    int n1,n2,k;
    cin>>n1;
    vector<int> v1(n1);
    for(int i=0;i<n1;i++) cin>>v1[i];
    cin>>n2;
    vector<int> v2(n2);
    for(int i=0;i<n2;i++) cin>>v2[i];
    cin>>k;
    vector<vector<int>> sol=Solution().kSmallestPairs(v1,v2,k);
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}