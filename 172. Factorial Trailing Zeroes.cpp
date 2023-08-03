#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursive
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        return n / 5 + trailingZeroes(n / 5);
    }
};

// Approach 2: Iterative
class Solution {
public:
    int trailingZeroes(int n) {
        int sol = 0;
        while (n) {
            sol += n / 5;
            n /= 5;
        }
        return sol;
    }
};

int main(){
    int n;
    cin>>n;
    cout<<Solution().trailingZeroes(n);
    return 0;
}