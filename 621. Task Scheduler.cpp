#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        vector<int> map(26, 0);
        for (int i = 0; i < size; i++) {
            map[tasks[i] - 'A']++;
        }
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            maxCount = max(maxCount, map[i]);
        }
        int maxCountTasks = 0;
        for (int i = 0; i < 26; i++) {
            if (map[i] == maxCount) {
                maxCountTasks++;
            }
        }
        int partCount = maxCount - 1;
        int partLength = n - (maxCountTasks - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = size - maxCount * maxCountTasks;
        int idles = max(0, emptySlots - availableTasks);
        return size + idles;
    }
};


int main() {
    int n, size;
    cin >> n >> size;
    vector<char> tasks(size);
    for (int i = 0; i < size; i++) {
        cin >> tasks[i];
    }
    cout << Solution().leastInterval(tasks, n);
    return 0;
}