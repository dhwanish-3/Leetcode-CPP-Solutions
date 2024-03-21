#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixProduct(n, 1);
        suffixProduct[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }
        int prefixProduct = nums[0];
        for (int i = 1; i < n - 1; i++) {
            suffixProduct[i] = prefixProduct * suffixProduct[i];
            prefixProduct *= nums[i];
        }
        suffixProduct[n - 1] = prefixProduct;
        return suffixProduct;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> sol = Solution().productExceptSelf(nums);
    for (int i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    return 0;
}