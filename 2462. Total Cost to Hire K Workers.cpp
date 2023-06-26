#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sol=0;
        int i=0;
        int j=costs.size()-1;
        priority_queue<int,vector<int>,greater<>> Left;
        priority_queue<int,vector<int>,greater<>> Right;

        for(int hired=0;hired<k;hired++){
            while(Left.size()<candidates && i<=j){
                Left.push(costs[i]);
                i++;
            }
            while(Right.size()<candidates && i<=j){
                Right.push(costs[j]);
                j--;
            }
            if(Left.empty()){
                sol+=Right.top();
                Right.pop();
            }else if(Right.empty()){
                sol+=Left.top();
                Left.pop();
            }else if(Left.top()<=Right.top()){
                sol+=Left.top();
                Left.pop();
            }else{
                sol+=Right.top();
                Right.pop();
            }
        }
        return sol;
    }
};

int main(){
    int n,k,cand;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>k>>cand;
    cout<<Solution().totalCost(v,k,cand);
    return 0;
}