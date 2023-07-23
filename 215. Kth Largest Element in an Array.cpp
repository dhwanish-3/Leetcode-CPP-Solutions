#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap{nums.begin(), nums.end()};
        int i = 1;
        while (!maxHeap.empty()) {
            if (i == k) {
                return maxHeap.top();
            }
            maxHeap.pop();
            i++;
        }
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Solution().findKthLargest(v, k);
    return 0;
}