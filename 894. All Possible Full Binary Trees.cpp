#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 ==0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        auto it = memo.find(n);
        if (it != memo.end()) {
            return it->second;
        }
        vector<TreeNode*> sol;
        for (int left = 0; left < n; left++) {
            int right = n - left - 1;
            for (auto  leftNode : allPossibleFBT(left)) {
                for (auto rightNode : allPossibleFBT(right)) {
                    sol.push_back(new TreeNode(0));
                    sol.back()->left = leftNode;
                    sol.back()->right = rightNode;
                }
            }
        }
        return memo[n] = sol;
    }
};

int main(){
    
    
    return 0;
}