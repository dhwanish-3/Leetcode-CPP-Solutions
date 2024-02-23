#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) {
            return 0;
        }
        int moveFactor = 1;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            moveFactor <<= 1;
        }
        return left * moveFactor;
    }
};

int main() {
    int left, right;
    cin >> left >> right;
    cout << Solution().rangeBitwiseAnd(left, right);
    return 0;
}