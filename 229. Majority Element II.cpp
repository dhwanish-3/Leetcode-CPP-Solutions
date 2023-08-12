#include <bits/stdc++.h>
using namespace std;

// Approach 1: HashMap
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol;
        int count = floor(n / 3);
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }
        for (auto it : hash) {
            if (it.second > count) {
                sol.push_back(it.first);
            }
        }
        return sol;
    }
};

// Approach 2: Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = floor(n / 3);
        int first = 0, second = 0;
        int possibleCandidate1 = 0, possibleCandidate2 = 1;
        vector<int> sol;
        for (int i = 0; i < n; i++) {
            if (nums[i] == possibleCandidate1) {
                first++;
            } else if (nums[i] == possibleCandidate2) {
                second++;
            } else if (first <= 0) {
                first = 1;
                possibleCandidate1 = nums[i];
            } else if (second <= 0) {
                second = 1;
                possibleCandidate2 = nums[i];
            } else {
                first--;
                second--;
            }
        }
        first = second = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == possibleCandidate1) {
                first++;
            } else if (nums[i] == possibleCandidate2) {
                second++;
            }
        }
        if (first > count) {
            sol.push_back(possibleCandidate1);
        }
        if (second > count) {
            sol.push_back(possibleCandidate2);
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> sol = Solution().majorityElement(v);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}