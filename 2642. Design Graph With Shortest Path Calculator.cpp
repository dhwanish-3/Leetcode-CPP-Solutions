#include <bits/stdc++.h>
using namespace std;

class Graph {
    vector<vector<pair<int, int>>> adjList;
private:
    int dijkstra(int start, int end) {
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            int curNode = pq.top().second;
            int curCost = pq.top().first;
            pq.pop();
            if (curCost > dist[curNode]) {
                continue;
            }
            if (curNode == end) {
                return curCost;
            }
            for (auto edge : adjList[curNode]) {
                int neighbour = edge.first;
                int edgeLen = edge.second;
                int newRouteCost = edgeLen + dist[curNode];
                if (newRouteCost < dist[neighbour]) {
                    dist[neighbour] = newRouteCost;
                    pq.push({newRouteCost, neighbour});
                }
            }
        }
        return (dist[end] == INT_MAX) ? -1 : dist[end];
    }
public:
    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for (auto edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    Graph graph(n, edges);
    int node1, node2;
    cin >> node1 >> node2;
    cout << graph.shortestPath(node1, node2);
    return 0;
}