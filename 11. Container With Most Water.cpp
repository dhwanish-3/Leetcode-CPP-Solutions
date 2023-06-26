#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0; 
        int left=0;
        int right=height.size()-1;
        while(left<right){
            maxArea=max(maxArea,(right-left)*(min(height[left],height[right])));
            cout<<maxArea<<endl;
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<Solution().maxArea(v);
    return 0;
}