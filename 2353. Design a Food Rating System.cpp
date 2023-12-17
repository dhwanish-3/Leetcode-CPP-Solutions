#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, set<pair<int, string>>> cuisineRatings;
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodToCuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            cuisineRatings[cuisines[i]].insert({ -ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        cuisineRatings[cuisine].erase({ -foodRating[food], food});
        cuisineRatings[cuisine].insert({ -newRating, food});
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineRatings[cuisine].begin()->second;
    }
};

int main() {
    
    return 0;
}