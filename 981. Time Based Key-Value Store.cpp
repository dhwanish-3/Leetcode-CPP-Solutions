#include <bits/stdc++.h>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back(make_pair(timestamp, value));
    }

    int getTimestamp(vector<pair<int, string>>& timestamps, int timestamp) {
        int n = timestamps.size();
        int l = 0, r = n - 1;
        int sol = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (timestamps[mid].first == timestamp) {
                return mid;
            } else if (timestamps[mid].first > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
                sol = mid;
            }
        }
        return sol;
    }
    
    string get(string key, int timestamp) {
        int in = getTimestamp(data[key], timestamp);
        if (in == -1) {
            return "";
        } else {
            return data[key][in].second;
        }
    }
};

int main() {
    
    return 0;
}