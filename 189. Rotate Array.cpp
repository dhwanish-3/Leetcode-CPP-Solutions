#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Extra Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        for(int j=0;j<nums.size();j++){
            v[(j+k)%nums.size()]=nums[j];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=v[i];
        }
    }
};

// Approach 2: O(1) Space
class Solution {
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int l = 0;
        int r = n - k - 1;
        reverse(nums, l, r);
        l = n - k;
        r = n - 1;
        reverse(nums, l, r);
        l = 0;
        r = n - 1;
        reverse(nums, l, r);
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution().rotate(nums,k);
    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }
    return 0;
}