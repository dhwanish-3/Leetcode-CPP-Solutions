#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);
        int maxLength = 1;
        int sol = 0;
        for (int i=1 ; i<n ; i++) {
            for (int j=0 ; j<i ; j++) {
                if (nums[i] > nums[j]) {
                    if (length[i] < length[j] + 1) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    } else if (length[i] == length[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            maxLength = max(maxLength, length[i]);
        }
        for (int i=0 ; i<n ; i++) {
            if (length[i] > maxLength) {
                maxLength = length[i];
                sol = count[i];
            } else if (length[i] == maxLength) {
                sol += count[i];
            }
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0 ; i<n ; i++) {
        cin>>v[i];
    }
    cout<<Solution().findNumberOfLIS(v);
    return 0;
}