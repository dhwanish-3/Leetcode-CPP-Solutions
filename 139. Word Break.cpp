#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dynamic(string s, vector<string>& wordDict, vector<int>& dp, int i) {
        if (i < 0) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i] == 1;
        }
        for (string word : wordDict) {
            int curLen = word.length();
            if (i - curLen + 1 < 0) {
                continue;
            }
            if (s.substr(i - curLen + 1, curLen) == word && dynamic(s, wordDict, dp, i - curLen)) {
                dp[i] = 1;
                return true;
            }
        }
        dp[i] = 0;
        return false;
    } 
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        int n = wordDict.size();
        vector<int> dp(len, -1);
        return dynamic(s, wordDict, dp, len -1);
    }
};

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> wordDict(n);
    for(int i=0;i<n;i++){
        cin>>wordDict[i];
    }
    cout<<Solution().wordBreak(s, wordDict);
    return 0;
}