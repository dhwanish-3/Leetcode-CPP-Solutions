#include <bits/stdc++.h>
using namespace std;

class Solution {
    void swap(char& a, char& b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    Solution().reverseString(s);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    return 0;
}