#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v(2);
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                v[0]=left+1;
                v[1]=right+1;
                return v;
            }
            else if(numbers[left]+numbers[right]>target){
                right--;
            }else{
                left++;
            }
        }
        return v;
    }
};

int main(){
    int n,tar;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>tar;
    vector<int> sol=Solution().twoSum(v,tar);
    for(int i=0;i<sol.size();i++) cout<<sol[i]<<" ";
    return 0;
}