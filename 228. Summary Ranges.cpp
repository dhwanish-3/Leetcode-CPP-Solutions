#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0) return vector<string>();
        vector<string> v;
        int count=0;
        string s;
        int i;
        for(i=1;i<nums.size();i++){
            if(count==0) s.append(to_string(nums[i-1]));
            count++;
            long long diff = static_cast<long long>(nums[i]) - static_cast<long long>(nums[i-1]);
            if(diff!=1){
                if(count==1) v.push_back(s);
                else{
                    s.append("->");
                    s.append(to_string(nums[i-1]));
                    v.push_back(s);
                }
                s.clear();
                count=0;
            }
        }
        count++;
        if(count==1) v.push_back(to_string(nums[i-1]));
        else{
            s.append("->");
            s.append(to_string(nums[i-1]));
            v.push_back(s);
        }
        return v;
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