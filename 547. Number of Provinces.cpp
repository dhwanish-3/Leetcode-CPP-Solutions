#include <bits/stdc++.h>
using namespace std;

class DisJointSet{
    vector<int> parent;
    vector<int> size;
public:
    DisJointSet(int n){
        parent=vector<int>(n);
        size=vector<int>(n,1);
        iota(parent.begin(),parent.end(),0); //initially, parent of every node is itself 
    }

    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x,int y){
        // if(size[x]>size[y]){
        //     parent[find(y)]=find(x);
        //     size[x]+=size[y];
        // }else{
            parent[find(x)]=find(y);
        //     size[y]+=size[x];
        // }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisJointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    ds.Union(i,j);
                }
            }
        }
        set<int> unique;
        for(int i=0;i<n;i++){
            unique.insert(ds.find(i));
        }
        return unique.size();
    }
};

int main(){
    int in,n;
    vector<vector<int>> connected;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> vctr;
        for(int j=0;j<n;j++){
            cin>>in;
            vctr.push_back(in);
        }
        connected.push_back(vctr);
    }
    cout<<Solution().findCircleNum(connected);
    return 0;
}