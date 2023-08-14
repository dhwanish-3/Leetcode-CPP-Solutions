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

struct compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, compare> q;
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for (int i = k; i < n; i++) {
            if (nums[i] > q.top()) {
                q.push(nums[i]);
            }
        }
        return q.top();
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