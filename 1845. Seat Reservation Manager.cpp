#include <bits/stdc++.h>
using namespace std;

class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int count = 0;
public:
    SeatManager(int n) {
        count = 1;
    }
    
    int reserve() {
        if (pq.empty()) {
            return count++;
        }
        int top = pq.top();
        pq.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

int main() {
    
    return 0;
}