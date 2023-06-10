#include <bits/stdc++.h>
using namespace std;

class Solution {
    long getMinimumSum(int n,int index,int tar){
        long l=min(index,tar-1);
        long r=min(n-index,tar);
        long leftSum=((tar-1)+(tar-l))*l/2;
        long rightSum=((tar+tar-r+1))*r/2;
        return leftSum+rightSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum-=n;
        int l=0;
        int r=maxSum;
        int mid=0;
        while(l<r){
            mid=(l+r)/2;
            cout<<getMinimumSum(n,index,mid)<<endl;
            if(getMinimumSum(n,index,mid)>=maxSum) r=mid;
            else l=mid+1;
        }
        return getMinimumSum(n,index,l)>maxSum?l:l+1;
    }
};

int main(){
    int n,index,maxSum;
    cin>>n>>index>>maxSum;
    cout<<Solution().maxValue(n,index,maxSum);
    return 0;
}