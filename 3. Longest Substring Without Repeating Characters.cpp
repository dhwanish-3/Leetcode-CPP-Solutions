#include <bits/stdc++.h>
using namespace std;

// Appraoch 1: Sliding Window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<char> hash;
        int l = 0;
        int maxLen = 0;
        for (int r = 0; r < len; r++) {
            while (hash.find(s[r]) != hash.end()) {
                hash.erase(s[l]);
                l++;
            }
            hash.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

// Approah 2: Sliding Window Optimized
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char, int> hash;
        int l = 0;
        int maxLen = 0;
        for (int r = 0; r < len; r++) {
            if (hash.find(s[r]) == hash.end()) {
                hash[s[r]] = r;
            } else {
                l = max(l, hash[s[r]] + 1);
                hash[s[r]] = r;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

int main(){
    string s;
    cin>>s;
    cout<<Solution().lengthOfLongestSubstring(s);    
    return 0;
}