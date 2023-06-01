#include <iostream>
using namespace std;

class MyHashSet {
    int Hash[1000001]={};
public:
    MyHashSet() {

    }
    
    void add(int key) {
        Hash[key]=1;
        // cout<<Hash[key]<<endl;
    }
    
    void remove(int key) {
        Hash[key]=0;
        // cout<<Hash[key]<<endl;
    }
    
    bool contains(int key) {
        // cout<<Hash[key]<<endl;
        return Hash[key]==0?false:true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(){
    MyHashSet* myHashSet = new MyHashSet();
    myHashSet->add(1);      // set = [1]
    myHashSet->add(2);      // set = [1, 2]
    cout<<"contains"<<myHashSet->contains(1)<<endl; // return True
    cout<<"contains"<<myHashSet->contains(3)<<endl; // return False, (not found)
    myHashSet->add(2);      // set = [1, 2]
    cout<<"contains"<<myHashSet->contains(2)<<endl; // return True
    myHashSet->remove(2);   // set = [1]
    cout<<"contains"<<myHashSet->contains(2)<<endl; // return False, (already removed)
    
    return 0;
}