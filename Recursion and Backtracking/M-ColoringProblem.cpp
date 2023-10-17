#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
// https://www.youtube.com/watch?v=wuVwUK25Rfc

class Solution {
   public:
    // Function to check if it's valid to color a node with a certain color
    bool isValid(bool graph[101][101], vector<int> colors, int node, int n, int color) {
        for (int k = 0; k < n; k++) {
            if (k != node && graph[k][node] && colors[k] == color)
                return false;
        }
        return true;
    }

    // Function to recursively check and assign colors to nodes
    bool checkColor(bool graph[101][101], int m, int n, vector<int> &colors, int node) {
        // if node == n , all the colors have been assigned successfuly
        if (node == n) return true;

        // try assigning all the colors one by one to the current node
        for (int i = 0; i < m; i++) {
            // check if the current color is safe to assign in the current node
            if (isValid(graph, colors, node, n, i)) {
                // since the color is valid, assign the color to the node
                colors[node] = i;
                // then try assigning colors to the next node
                bool res = checkColor(graph, m, n, colors, node + 1);
                // if res is true, all the following nodes were assigned colors successfuly so we return true
                if (res)
                    return true;
                // if res is false, the current color can not give us a sucessful coloring.
                // So, we backtrack by removing the current color ( i.e changing to to the default)
                else
                    colors[node] = -1;
            }
        }
        // since no possible color assignment was found, return false
        return false;
    }

    // Master function to perform graph coloring
    bool graphColoring(bool graph[101][101], int m, int n) {
        // initialise a vector to keep track of the assigned colors
        vector<int> colors(n, -1);
        return checkColor(graph, m, n, colors, 0);
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}