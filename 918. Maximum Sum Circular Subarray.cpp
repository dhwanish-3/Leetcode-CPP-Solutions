#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int curMaxSum = 0;
        int curMinSum = 0;
        int curSum = 0;
        int n = nums.size();
        for (int i = 0; i < n ; i++) {
            curSum += nums[i];
            curMaxSum = max(curMaxSum + nums[i], nums[i]);
            curMinSum = min(curMinSum + nums[i], nums[i]);
            cout <<"curMaxSum " <<curMaxSum <<"  curMinSum " << curMinSum << endl;
            maxSum = max(maxSum, curMaxSum);
            minSum = min(minSum, curMinSum);
            cout <<"maxSum " <<maxSum <<"  minSum " << minSum << endl;
        }
        if (maxSum < 0) {
            return maxSum;
        } else {
            return max(maxSum, curSum - minSum);
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    cout<<Solution().maxSubarraySumCircular(v)<<endl;
    return 0;
}