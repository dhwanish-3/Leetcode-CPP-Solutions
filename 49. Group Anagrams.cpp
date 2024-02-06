#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) {
            anagrams.push_back(p.second);
        }
        return anagrams;
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