#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int sol = 0;
        queue<int> q{{1}};
        vector<bool> visited(1 + (n*n), false);
        vector<int> A(1 + (n*n));
        for (int i=0 ;i<n ;i++) {
            bool reverse = n - i & 1 ;
            for (int j=0; j<n; j++) {
                if (reverse){
                    A[(n-i-1)*n + n-j] = board[i][j];
                } else {
                    A[(n-i-1)*n + j+1] = board[i][j];
                }
            }
        }
        while (!q.empty()) {
            sol++;
            for (int size=q.size() ;size>0 ;size--) {
                int cur = q.front();
                q.pop();
                for (int next=cur+1 ;next<=min(cur+6, n*n) ;next++) {
                    int dest = A[next]>0 ? A[next]: next;
                    if (dest == n*n) {
                        return sol;
                    }
                    if (visited[dest]) {
                        continue;
                    }
                    q.push(dest);
                    visited[dest] = true;
                }
            }
        }
        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i=0 ;i<n ;i++) {
        for (int j=0; j<n ;j++) {
            cin>>v[i][j];
        }
    }
    cout<<Solution().snakesAndLadders(v);
    return 0;
}