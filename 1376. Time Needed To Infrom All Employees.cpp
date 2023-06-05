#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> Tree;
        stack<pair<int,int>> stk;
        for(int i=0;i<n;i++){
            Tree[manager[i]].push_back(i);
        }
        stk.push(make_pair(headID,0));
        int totalTime=0;
        while(!stk.empty()){
            pair<int,int> p=stk.top();
            stk.pop();
            int node=p.first;
            int currTime=p.second;
            totalTime=max(currTime,totalTime);
            for(int child: Tree[node]){
                stk.push(make_pair(child,currTime+informTime[node]));
            }
        }
        return totalTime;
    }
};

int main(){
    int n,head,in;
    cin>>n>>head;
    vector<int> manager;
    vector<int> informTime;
    for(int i=0;i<n;i++){
        cin>>in;
        manager.push_back(in);
    }
    for(int i=0;i<n;i++){
        cin>>in;
        informTime.push_back(in);
    }
    cout<<Solution().numOfMinutes(n,head,manager,informTime);
    return 0;
}