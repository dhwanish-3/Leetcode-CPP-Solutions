#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> sol;
        for (int ast : asteroids) {
            if (ast > 0) {
                sol.push_back(ast);
            } else {
                while (!sol.empty() && sol.back() > 0 && sol.back() < -ast) {
                    sol.pop_back();
                }
                if (sol.empty() || sol.back() < 0) {
                    sol.push_back(ast);
                } else if (sol.back() == -ast) {
                    sol.pop_back();
                }
            }
        }
        return sol;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }
    vector<int> sol = Solution().asteroidCollision(asteroids);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}