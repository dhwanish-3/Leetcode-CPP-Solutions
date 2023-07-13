#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int size;
    unordered_map<int, list<pair<int,int>>::iterator> keyToPair;
    list<pair<int, int>> cache;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = keyToPair.find(key);
        if (it == keyToPair.end()) return -1;
        // Move to front
        auto& listIt = it->second;
        cache.splice(cache.begin(), cache, listIt);
        return listIt->second;
    }
    
    void put(int key, int value) {
        // No capacity issue, just update the value
        const auto it = keyToPair.find(key);
        if (it != keyToPair.end()) {
            auto& listIt = it->second;
            // Move to front
            cache.splice(cache.begin(), cache, listIt);
            listIt->second = value;
            return;
        }
        // Check the capacity
        if (cache.size() == size) {
            auto& lastPair = cache.back();
            // that's why we store `key` in `Node`
            keyToPair.erase(lastPair.first);
            cache.pop_back();
        }
        cache.emplace_front(key,value);
        keyToPair[key] = cache.begin();
    }
};

int main(){
    int n;
    
    return 0;
}