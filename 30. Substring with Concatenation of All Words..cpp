#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int k=words.size();
        if (s.empty() || k==0) return {};
        int n=words[0].length();
        vector<int> sol;
        unordered_map<string,int> hash;
        for(const string& word: words){
            hash[word]++;
        }
        for(int i=0;i<s.length()-k*n+1;i++){
            unordered_map<string,int> visited;
            int j=0;
            for(;j<k;j++){
                const string& word=s.substr(i+j*n,n);
                if(++visited[word]>hash[word]){
                    break;
                }
            }
            if(j==k){
                sol.push_back(i);
            }
        }
        return sol;
    }
};

int main(){
    int n;
    string s;
    cin>>s;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> sol=Solution().findSubstring(s,v);
    for(int i=0;i<sol.size();i++) cout<<v[i];
    return 0;
}