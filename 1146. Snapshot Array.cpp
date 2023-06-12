#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
    vector<vector<pair<int,int>>> snapShots;
    int snap_id=0;
public:
    SnapshotArray(int length) : snapShots(length) {
        for(auto& snap: snapShots){
            snap.emplace_back(0,0);
        }
    }
    
    void set(int index, int val) {
        int& lastSnap_id=snapShots[index].back().first;
        int& lastValue=snapShots[index].back().second;
        if(lastSnap_id==snap_id) lastValue=val;
        else snapShots[index].emplace_back(snap_id,val);
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        const vector<pair<int, int>>& snap = snapShots[index];
        auto it = lower_bound(begin(snap), end(snap), make_pair(snap_id + 1, 0));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main(){
    int len,in;
    cin>>len;
    SnapshotArray* obj = new SnapshotArray(len);
    obj->set(0,5);
    cout<<obj->snap()<<endl;
    obj->set(0,6);
    cout<<obj->get(0,0)<<endl;
    return 0;
}