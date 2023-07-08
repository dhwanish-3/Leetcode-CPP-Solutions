#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    unordered_map<int,int> hash;
    vector<int> values;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.count(val)){
            return false;
        }
        hash[val]=values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(hash.count(val)==0){
            return false;
        }
        int index=hash[val];
        hash[values.back()]=index;
        hash.erase(val);
        values[index]=values.back();
        values.pop_back();
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};

int main(){
    RandomizedSet* obj = new RandomizedSet();
    cout<<obj->insert(1)<<endl;
    cout<<obj->remove(2)<<endl;
    cout<<obj->insert(2)<<endl;
    cout<<obj->getRandom()<<endl;
    cout<<obj->remove(1)<<endl;
    cout<<obj->insert(2)<<endl;
    cout<<obj->getRandom()<<endl;
    return 0;
}