#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasSum = 0;
        int totalCost = 0;
        for(int i=0 ; i<n ; i++){
            gasSum += gas[i];
            totalCost += cost[i];
        }
        if(gasSum < totalCost) return -1;
        int start = 0;
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                start = i+1;
            }
        }
        return start;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> gas(n);
    vector<int> cost(n);
    for(int i=0;i<n;i++) cin>>gas[i];
    for(int i=0;i<n;i++) cin>>cost[i];
    cout<<Solution().canCompleteCircuit(gas,cost);
    return 0;
}