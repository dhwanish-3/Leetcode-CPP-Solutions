#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int sol = 0;
        for (int i = 0; i < n; i++) {
            sol = min(sol + 1, arr[i]);
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().maximumElementAfterDecrementingAndRearranging(arr) << endl;
    return 0;
}