#include <bits/stdc++.h>
using namespace std;
#define NULL nullptr

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
    Node* divide(vector<vector<int>>& grid, int x, int y, int l) {
        if (l == 1) return new Node(grid[x][y] == 1, true);
        int one = 0;
        for (int i = x; i < x + l; i++) {
            for (int j = y; j < y + l; j++) {
                if (grid[i][j] == 1) {
                    one++;
                }
            }
        }
        Node* node;
        if (one == l * l) {
            node = new Node(true, true);
        } else if (one == 0) {
            node = new Node(false, true);
        } else {
            node = new Node(true, false);
            node->topLeft = divide(grid, x, y, (l / 2));
            node->bottomLeft = divide(grid, x + (l / 2), y, (l / 2));
            node->topRight = divide(grid, x, y + (l / 2), (l / 2));
            node->bottomRight = divide(grid, x + (l / 2), y + (l / 2), (l / 2));
        }
        return node;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return divide(grid, 0, 0, grid.size());
    }
};