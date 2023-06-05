#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {        
        int n=bombs.size();
        vector<vector<int>> graph(n,vector<int>());
        int x1,y1,r1;
        int x2,y2,r2;
        for(int i=0;i<n;++i){
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;++j){
                if(i==j) continue;
                x2=bombs[j][0];
                y2=bombs[j][1];
                r2=bombs[j][2];
                if(pow(x2-x1,2)+pow(y2-y1,2)<=pow(r1,2)){
                    graph[i].push_back(j);
                }
            }
        }
        int maxDetonations=0;
        for(int i=0;i<n;++i){
            vector<bool> visited(n,false);
            visited[i]=true;
            deque<int> q;
            q.push_back(i);
            int detonations=1;
            while(!q.empty()){
                int node=q.front();
                q.pop_front();
                for(int nbh : graph[node]){
                    if(!visited[nbh]){
                        visited[nbh]=true;
                        q.push_back(nbh);
                        detonations++;
                    }
                }
            }
            maxDetonations=max(maxDetonations,detonations);
        }
        return maxDetonations;
    }
};

int main(){
    int n,input1,input2,input3;
    vector<vector<int>> bombs;    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input1>>input2>>input3;
        vector<int> bomb;
        bomb.push_back(input1);
        bomb.push_back(input2);
        bomb.push_back(input3);
        bombs.push_back(bomb);
    }
    cout<<Solution().maximumDetonation(bombs)<<endl;
    return 0;
}