#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size() + 1;
        vector<int> pre(n, 0);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }
        int sol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pre[i] == pre[j]) {
                    sol += j - i - 1;
                }
            }
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
    cout << Solution().countTriplets(arr) << "\n";
    return 0;
}