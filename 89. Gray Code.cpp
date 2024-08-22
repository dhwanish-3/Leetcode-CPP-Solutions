#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> sol;
    void rec(bitset<32>& bits, int k) {
        if (k == 0) {
            sol.push_back(bits.to_ulong());
        } else {
            rec(bits, k - 1);
            bits.flip(k - 1);
            rec(bits, k - 1);
        }
    }
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        rec(bits, n);
        return sol;
    }
};