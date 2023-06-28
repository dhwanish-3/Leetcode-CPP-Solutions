#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int ,double>>> graph(n);
        priority_queue<pair<double,int>> maxHeap;
        maxHeap.emplace(1.0,start);
        vector<bool> visited(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            graph[u].emplace_back(v,prob);
            graph[v].emplace_back(u,prob);
        }
        while(!maxHeap.empty()){
            double prob=maxHeap.top().first;
            int u=maxHeap.top().second;
            maxHeap.pop();
            if(u==end)  return prob;
            if(visited[u]) continue;
            visited[u]=true;
            for(int i=0;i<graph[u].size();i++){
                int& next=graph[u][i].first;
                double& edgeProb=graph[u][i].second;
                if(visited[next]) continue;
                maxHeap.emplace(prob*edgeProb,next);
            }
        }
        return 0;
    }
};

int main(){
    int n,start,end;
    cin>>n;
    vector<vector<int>> edges(n,vector<int>(2));
    vector<double> prob(n);
    for(int i=0;i<n;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    for(int i=0;i<n;i++){
        cin>>prob[i];
    }
    cin>>start>>end;
    cout<<Solution().maxProbability(n,edges,prob,start,end);
    return 0;
}