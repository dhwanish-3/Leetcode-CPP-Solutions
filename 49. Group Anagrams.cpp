#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            hash[s].push_back(strs[i]);
        }
        vector<vector<string>> sol;
        for(auto it:hash){
            sol.push_back(it.second);
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<string>> sol=Solution().groupAnagrams(v);
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++){
            cout<<sol[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
}