#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum;
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            auto res=hash.find(target-nums[i]);
            if(res!=hash.end() && res->second!=i){                
                sum.push_back(i);
                sum.push_back(res->second);
                return sum;
            }
        }
        return sum;
    }
};

int main(){
    int n,in,tar;
    vector<int> nums;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in;
        nums.push_back(in);
    }
    cin>>tar;
    cout<<Solution().twoSum(nums,tar)[0]<<" ";
    cout<<Solution().twoSum(nums,tar)[1]<<endl;
    return 0;
}