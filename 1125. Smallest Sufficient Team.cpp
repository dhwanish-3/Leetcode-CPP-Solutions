#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getSkill(vector<string>& person, unordered_map<string, int>& skillToId) {
        int mask = 0;
        for (const string& skill : person) {
            auto it = skillToId.find(skill);
            if (it != skillToId.end()){
                mask = mask | 1<<it->second;
            }
        }
        return mask;
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int nSkills = 1 << n;
        unordered_map<string, int> skilltoId;
        // dp[i] min people's indices to cover skillset of mask i
        unordered_map<int, vector<int>> dp;
        dp.reserve(nSkills);
        dp[0] = {};
        for (int i=0 ;i<n ; i++) {
            skilltoId[req_skills[i]] = i;
        }
        int size = people.size();
        for (int i=0 ; i<size ; i++) {
            int currSkill = getSkill(people[i], skilltoId);
            for (auto& it : dp) {
                int mask = it.first;
                vector<int> indices = it.second;
                int newSkillSet = mask | currSkill;
                if (newSkillSet == mask) { // Adding people[i] does not increase skill set
                    continue;
                }
                if (!dp.count(newSkillSet) || dp[newSkillSet].size()>indices.size()+1) {
                    dp[newSkillSet] = indices;
                    dp[newSkillSet].push_back(i);
                }
            }
        }
        return dp[nSkills-1];
    }
};

int main(){
    int n,k,size;
    string in;
    cin>>n;
    vector<string> req(n);
    for (int i=0 ;i<n ; i++) cin>>req[i];
    cin>>size;
    vector<vector<string>> people(size);
    for (int i=0 ; i<size ; i++) {
        cin>>k;
        for (int j = 0 ;j<k ; j++) {
            cin>>in;
            people[i].push_back(in);
        }
    }
    
    return 0;
}