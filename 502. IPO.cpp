#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> comb(n);
        for (int i = 0; i < n; i++) {
            comb[i] = make_pair(capital[i], profits[i]);
        }
        sort(comb.begin(), comb.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });
        priority_queue<int> pq;
        int prev = 0;
        while (k--) {
            while (prev < n && comb[prev].first <= w) {
                pq.push(comb[prev].second);
                prev++;
            }
            if (pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

class Solution2 {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < n; i++) {
            if (capital[i] <= w) {
                maxHeap.push(profits[i]);
            } else {
                minHeap.push({capital[i], profits[i]});
            }
        }
        while (k--) {
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};