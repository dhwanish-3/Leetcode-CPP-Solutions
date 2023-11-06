#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = 0;
        for (int i : left) {
            maxLeft = max(maxLeft, i);
        }
        int minRight = n;
        for (int i : right) {
            minRight = min(minRight, i);
        }
        return max(maxLeft, n - minRight);
    }
};

int main() {
    int n, size;
    cin >> n >> size;
    vector<int> left(size);
    for (int i = 0; i < size; i++) {
        cin >> left[i];
    }
    cin >> size;
    vector<int> right(size);
    for (int i = 0; i < size; i++) {
        cin >> right[i];
    }
    cout << Solution().getLastMoment(n, left, right) << endl;
    return 0;
}