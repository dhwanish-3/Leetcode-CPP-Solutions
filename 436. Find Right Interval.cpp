#include <bits/stdc++.h>
using namespace std;

// BruteForce
class Solutio {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> sol(n, -1);
        for (int i = 0; i < n; i++) {
            int minJ = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (intervals[j][0] >= intervals[i][1] && minJ > intervals[j][0]) {
                    sol[i] = j;
                    minJ = intervals[j][0];
                }
            }
        }
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
        return sol;
    }
};

// Optimized
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> indices(n, 0);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return intervals[a][0] < intervals[b][0];
        });
        vector<int> sol(n, -1);
        for (int i = 0; i < n; i++) {
            sol[indices[i]] = binarySearch(intervals, indices, intervals[indices[i]][1]);
        }
        return sol;
    }

    int binarySearch(vector<vector<int>>& arr, vector<int>& indices, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int sol = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[indices[mid]][0] == target) {
                return indices[mid];
            } else if (arr[indices[mid]][0] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
                sol = indices[mid];
            }
        }
        return sol;
    }
};

int main() {
    vector<vector<int>> in1 = {{1,2}};
    vector<vector<int>> in2 = {{1,2}, {2,3}, {3,4}};
    vector<vector<int>> in3 = {{1,4},{2,3},{3,4}};
    Solution().findRightInterval(in1);
    Solution().findRightInterval(in2);
    Solution().findRightInterval(in3);
    return 0;
}