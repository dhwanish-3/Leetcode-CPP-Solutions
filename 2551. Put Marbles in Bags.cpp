#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> A;
        for(int i=0;i<n-1;i++){
            A.push_back(weights[i]+weights[i+1]);
        }
        sort(A.begin(),A.end());
        int size=A.size();
        long long min=0;
        long long max=0;
        for(int i=0;i<k-1;i++){
            min+=A[i];
            max+=A[size-i-1];
        }
        return max-min;
    }
};

int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>k;
    cout<<Solution().putMarbles(v,k);
    return 0;
}