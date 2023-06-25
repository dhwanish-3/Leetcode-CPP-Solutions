#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> copy=nums1;
        while(k<m+n){
            if(i<m && j<n){
                if(copy[i]<nums2[j]){
                    nums1[k]=copy[i];
                    i++;
                }else{
                    nums1[k]=nums2[j];
                    j++;
                }
            }else if(i<m){
                nums1[k]=copy[i];
                i++;
            }else if(j<n){
                nums1[k]=nums2[j];
                j++;
            }
            k++;
        }
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> nums1(m+n,0);
    vector<int> nums2(n);
    for(int i=0;i<m;i++) cin>>nums1[i];
    for(int i=0;i<n;i++) cin>>nums2[i];
    Solution().merge(nums1,m,nums2,n);
    return 0;
}