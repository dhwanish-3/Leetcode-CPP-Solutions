#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> sol;
        for (int i=0 ;i<asteroids.size() ; i++) {
            if (asteroids[i] > 0) {
                sol.push_back(asteroids[i]);
            } else {
                while (!sol.empty() && sol.back() > 0 && sol.back() < -asteroids[i]) {
                    sol.pop_back();
                }
                if (sol.empty() || sol.back() < 0) {
                    sol.push_back(asteroids[i]);
                } else if (sol.back() == -asteroids[i]) {
                    sol.pop_back();
                }
            }
        }
        return sol;
    }
};

int main(){
    
    
    return 0;
}