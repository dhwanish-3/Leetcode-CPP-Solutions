#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[2001] = {0};
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            hash[arr[i] + 1000]++;
        }
        int hash2[1001] = {0};
        for (int i = 0; i < 2001; i++) {
            hash2[hash[i] ]++;
        }
        for (int i = 1; i < 1001; i++) {
            if (hash2[i] > 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().uniqueOccurrences(arr);
    return 0;
}