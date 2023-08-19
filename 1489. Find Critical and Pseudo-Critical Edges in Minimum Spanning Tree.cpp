#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> f, rank;
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (x == f[x]) {
            return x;
        } else {
            return f[x] = find(f[x]);
        }
    }

    void Union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (rank[fx] > rank[fy]) {
            swap(fx, fy);
        }
        f[fx] = fy;
        if (rank[fx] == rank[fy]) {
            rank[fy]++;
        }
    }
};

class Solution {
    int getMST(int n, vector<vector<int>>& edges, int blockEdge, int preEdge = -1) {
        UnionFind uf(n);
        int weight = 0;
        if (preEdge != -1) {
            weight += edges[preEdge][2];
            uf.Union(edges[preEdge][0], edges[preEdge][1]);
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == blockEdge) {
                continue;
            }
            auto& edge = edges[i];
            if (uf.find(edge[0]) == uf.find(edge[1])) {
                continue;
            }
            uf.Union(edge[0], edge[1]);
            weight += edge[2];
        }
        for (int i = 0; i < n; i++) {
            if (uf.find(i) != uf.find(0)) {
                return INT_MAX;
            }
        }
        return weight;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int originalMST = getMST(n, edges, -1);
        vector<int> critical, pseudoCritical;
        for (int i = 0; i < edges.size(); i++) {
            if (getMST(n, edges, i) > originalMST) {
                critical.push_back(edges[i][3]);
            } else if (originalMST == getMST(n, edges, -1, i)) {
                pseudoCritical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudoCritical};
    }
};

int main() {
    int n, size;
    cin >> n >> size;
    vector<vector<int>> edges(size, vector<int>(3));
    for (int i = 0; i < size; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    vector<vector<int>> sol = Solution().findCriticalAndPseudoCriticalEdges(n, edges);
    for (int i = 0; i < sol[0].size(); i++) {
        cout << sol[0][i] << " ";
    }
    cout << endl;
    for (int i = 0; i < sol[1].size(); i++) {
        cout << sol[1][i] << " ";
    }
    cout << endl;
    return 0;
}