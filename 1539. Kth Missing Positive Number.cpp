#include <bits/stdc++.h>
using namespace std;

// Brute Force: O(n)
class Solution0 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        bool nums[1001] = {false};
        for (int i = 0; i < n; i++) {
            nums[arr[i]] = true;
        }
        int count = 0;
        for (int i = 1; i < 1001; i++) {
            if (!nums[i]) {
                count++;
            }
            if (count == k) {
                return i;
            }
        }
        return arr[n - 1] + 1;
    }
};

// Brute Force: O(n)
class Solution1 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int count = arr[0] - 1;
        if (count >= k) {
            return k;
        }
        for (int i = 1; i < n; i++) {
            count += arr[i] - arr[i - 1] - 1;
            if (count >= k) {
                return arr[i - 1] + k - (count - arr[i] + arr[i - 1] + 1);
            }
        }
        return arr[n - 1] + k - count;
    }
};

// Binary Search: O(nlogn)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int count = arr[0] - 1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            count = arr[mid] - mid - 1;
            if (count >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l + k;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Solution().findKthPositive(arr, k) << "\n";
    return 0;
}