#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[letters.size()-1]<target) return letters[0];
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target) return letters[i];
        }
        return letters[0];
    }
};

int main(){
    int n;
    cin>>n;
    vector<char> v;char ch;
    while(n--){
        cin>>ch;
        v.push_back(ch);
    }
    cin>>ch;
    cout<<Solution().nextGreatestLetter(v,ch);
    return 0;
}