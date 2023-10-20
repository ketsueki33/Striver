#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/n-queens/

class Solution {
    // declaring hash arrays to optimize the isValid() function.
    // These will be used to store whether a queen exists in a specific direction
    vector<bool> horizontal;
    vector<bool> diag45;
    vector<bool> diag135;

   public:
    // Function to check if it is safe to place a queen at the co-ordinate
    bool isValidOptimised(int row, int col, int n) {
        // check in the horizontal line
        if (horizontal[row] == true)
            return false;
        // check in the 45° line
        if (diag45[row + col] == true)
            return false;
        // check in the 135° line
        if (diag135[row - col + n - 1] == true)
            return false;
        // no need to check for vertical line as we are placing only one queen in each column

        // since there are no clashes, return true
        return true;
    }

    // Function to recurively place queens column by column
    void queenSolver(int n, vector<vector<string>> &res, vector<string> &layout, int col) {
        // if n == col , this means all the queens have been placed, hence push the answer to result list and return
        if (col == n) {
            res.push_back(layout);
            return;
        }

        // try placing queen in the current column at each row
        for (int row = 0; row < n; row++) {
            // check if a queen can be placed at the current [row][col]
            if (isValidOptimised(row, col, n)) {
                // Since the queen can be placed, place the Queen and adjust the hash
                layout[row][col] = 'Q';
                horizontal[row] = true;
                diag45[row + col] = true;
                diag135[row - col + n - 1] = true;

                // try placing the next queen in the next column
                queenSolver(n, res, layout, col + 1);

                // Bactrack by removing the queen and readjusting the hash to the previous values
                layout[row][col] = '.';
                horizontal[row] = false;
                diag45[row + col] = false;
                diag135[row - col + n - 1] = false;
            }
        }
    }

    // Master function to to place N Queens on a nxn chess board
    vector<vector<string>> solveNQueens(int n) {
        // initializing the default chess board with no queens placed
        string str(n, '.');
        vector<string> layout(n, str);

        // declaring a list to store all the valid board layouts
        vector<vector<string>> res;

        // intialising the hash arrays for isValid() optimization
        for (int i = 0; i < n; i++)
            horizontal.push_back(false);
        for (int i = 0; i < (2 * n) - 1; i++) {
            diag135.push_back(false);
            diag45.push_back(false);
        }

        queenSolver(n, res, layout, 0);

        return res;
    }

// unoptimised isValid() function. Time complexity is O(3n)
    bool isValidUnoptimised(int row, int col, vector<string> layout, int n) {
        //  check in the left direction
        for (int i = 0; i < col; i++) {
            if (layout[row][i] == 'Q')
                return false;
        }

        // check in the upper-left direction
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (layout[i][j] == 'Q')
                return false;
        }

        // check in the lower-left direction
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (layout[i][j] == 'Q')
                return false;
        }

        // we are placing queens one column at at time so we know there is only one queen in a single column
        // hence, no need to check in the up and down direction.
        // we are placing queens from left column to right column, so the placed queens exist only before the current
        // column, hence no need to check in the right, upper-right and lower-right direction

        return true;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<string>> res = obj.solveNQueens(4);

    for (auto z : res) {
        for (auto x : z) {
            for (auto y : x)
                cout << y;
            cout << endl;
        }
        cout << "********" << endl;
    }

    return 0;
}