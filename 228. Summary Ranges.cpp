#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        vector<string> sol;
        int count = 0;
        string s;
        int i;
        for(i = 1; i < n; i++){
            if(count == 0) {
                s.append(to_string(nums[i-1]));
            }
            count++;
            long long diff = (long long)(nums[i]) - (long long)(nums[i-1]);
            if (diff != 1) {
                if(count == 1) {
                    sol.push_back(s);
                }
                else{
                    s.append("->");
                    s.append(to_string(nums[i-1]));
                    sol.push_back(s);
                }
                s.clear();
                count=0;
            }
        }
        return sol;
    }
};

int main(){
    int n,in;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>in;
        v.push_back(in);
    }
    vector<string> str=Solution().summaryRanges(v);
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<endl;
    }
    return 0;
}