#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// https://youtu.be/bLGZhJlt4y0

class Solution {
    // Displacements for moving in 4 directions: Up, Right, Down, Left
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};
    // Corresponding direction characters: Up, Right, Down, Left
    char dc[4] = {'U', 'R', 'D', 'L'};

   public:
    // Function to check if a cell at (x, y) is a valid move in the maze
    bool isValid(int x, int y, vector<vector<int>> &maze, int n) {
        // the move is valid if the cell coordinates are valid and maze[x][y]=1
        if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1)
            return true;
        else
            return false;
    }

    // Recursive function to explore and find paths in the maze
    void checkPath(vector<vector<int>> &maze, int n, vector<string> &ans, string &path, int x, int y) {
        // if we have reached the destination, add the path to the list of answers
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // checking all four directions one by one
        for (int i = 0; i < 4; i++) {
            // set the new direction
            int xNew = x + dx[i];
            int yNew = y + dy[i];

            // check if we can move in the new direction
            if (isValid(xNew, yNew, maze, n)) {
                // Since, the new direction is valid, add the direction character to the current path
                path += dc[i];
                // Also mark the cell as visited (-1) to avoid repetition of cells in the path
                maze[xNew][yNew] = -1;
                checkPath(maze, n, ans, path, xNew, yNew);

                // after all the paths from the new direction have been checked, we backtrack so that
                // other possible paths can be added to the answer list
                path.pop_back();       // Backtrack: remove the last direction character
                maze[xNew][yNew] = 1;  // Backtrack: restore the cell to its original state
            }
        }
        return;
    }

    // Master function to find all paths in the maze
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // A vector to store the found paths
        vector<string> ans;

        // If the start or end cell is blocked, return an empty list
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        // initialise a string to keep track of the path
        string path = "";

        // Mark the start cell as visited (-1) to avoid repetition of this cell in a path
        maze[0][0] = -1;
        checkPath(maze, n, ans, path, 0, 0);
        // Restore the start cell to its original state
        maze[0][0] = 1;
        return ans;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}