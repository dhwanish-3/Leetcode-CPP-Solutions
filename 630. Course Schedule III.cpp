#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        int time = 0;
        priority_queue<int> q;
        for (int i = 0; i < courses.size(); i++) {
            time += courses[i][0];
            q.push(courses[i][0]);
            if (time > courses[i][1]) {
                time -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (2));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    cout << Solution().scheduleCourse(v) << endl;
    return 0;
}