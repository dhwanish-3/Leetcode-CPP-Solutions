#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> count(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++){
            count[min(n,citations[i])]++;
        }
        for(int i=n;i>=0;i--){
            sum+=count[i];
            if(sum>=i) return i;
        }
        return 0;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().hIndex(v);
    return 0;
}