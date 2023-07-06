#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string sol=strs[0];
        for(int i=0;i<n;i++){
            int j=0;
            int len=sol.length();
            int str=strs[i].length();
            while(j<len && j<str && sol[j]==strs[i][j]){
                j++;
            }
            sol.resize(j);
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().longestCommonPrefix(v);
    return 0;
}