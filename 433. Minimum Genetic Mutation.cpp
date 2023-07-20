#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet{bank.begin(), bank.end()};
        if (!bankSet.count(endGene)) {
            return -1;
        }
        int sol = 0;
        vector<char> Genes = {'A', 'C', 'G', 'T'};
        queue<string> q{{startGene}};
        while (!q.empty()) {
            sol++;
            for (int size = q.size() ; size>0 ; size--) {
                string word = q.front();
                q.pop();
                for (int i=0 ; i<word.length() ; i++) {
                    char cache = word[i];
                    for (char c : Genes) {
                        word[i] = c;
                        if (word == endGene) {
                            return sol;
                        }
                        if (bankSet.count(word)) {
                            bankSet.erase(word);
                            q.push(word);
                        }
                    }
                    word[i] = cache;
                }
            }
        }
        return -1;
    }
};

int main(){
    string a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    vector<string> v(n);
    for (int  i=0 ; i<n ; i++) {
        cin>>v[i];
    }
    cout<<Solution().minMutation(a,b,v);
    return 0;
}