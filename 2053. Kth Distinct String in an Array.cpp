#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hash;
        for (auto it : arr) {
            hash[it]++;
        }
        for (auto it : arr) {
            if (hash[it] == 1) {
                k--;
            }
            if (k == 0) {
                return it;
            }
        }
        return "";
    }
};