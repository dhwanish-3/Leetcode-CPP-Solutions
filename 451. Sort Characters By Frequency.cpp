#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<int> hash(128, 0);
        for (char c : s) {
            hash[c - '0']++;
        }
        sort(s.begin(), s.end(), [hash](char& a,  char& b){
            if (hash[a - '0'] == hash[b - '0']) {
                return a > b;
            }
            return hash[a - '0'] > hash[b - '0'];
        });
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().frequencySort(s);
    return 0;
}