#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        for(int j=0;j<nums.size();j++){
            v[(j+k)%nums.size()]=nums[j];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=v[i];
        }
    }
};

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    
    int count = 0;
    
    for(int start = 0; count < n; ++start){
        int cur = start;
        //temporarily store the value k position before nums[next]
        int prev = nums[cur];
        do{
            int next = (cur+k) % n;
            // cout << "nums[" << next << "]: " << prev << endl;
            swap(nums[next], prev);
            cur = next;
            ++count;
        }while(cur != start);
    }
}

int main(){
    
    
    return 0;
}