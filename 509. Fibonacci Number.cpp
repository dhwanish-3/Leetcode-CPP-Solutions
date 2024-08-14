#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
    // Dynamic programming
    int fibonacci(int n) {
        if(n < 2) return n;
        vector<int> fibonacciSeries(n + 1);
        fibonacciSeries[0] = 0;
        fibonacciSeries[1] = 1;
        for (int i = 2; i < n + 1; i++){
            fibonacciSeries[i] = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
        }
        return fibonacciSeries[n];
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().fibonacci(n);    
    return 0;
}