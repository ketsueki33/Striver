#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/sudoku-solver/
// https://youtu.be/FWAIf_EVUKE

class Solution {
   public:
    // function to check if a character can be placed in the specified cell
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // we can check for all conditions in a single iteratiom:
        // 1. Each row must have unique numbers from 1 to 9.
        // 2. Each column must have unique numbers from 1 to 9.
        // 3. Each of the nine 3x3 subgrids (or boxes) must have unique numbers from 1 to 9.
        for (int i = 0; i < 9; i++) {
            // check in the cell column
            if (board[i][col] == c)
                return false;

            // check in the cell row
            if (board[row][i] == c)
                return false;

            // check in the cell sub-grid. This if statement works as follows:
            // 1. (row / 3) and (col / 3) calculate which 3x3 subgrid (box) the current cell (row, col) belongs to.
            //    This division operation effectively "rounds down" the row and column coordinates to the nearest multiple of 3.
            // 2. 3 * (row / 3) and 3 * (col / 3) give you the top-left cell of the subgrid (box) to which
            //    the current cell belongs.
            // 3. i / 3 and i % 3 are used to iterate through the cells within the current subgrid (box). i / 3 determines
            //    the row offset within the subgrid (0, 1, or 2), and i % 3 determines the column offset within the subgrid (0, 1, or 2).
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    // function to recursively place a number in the next empty cell
    bool solver(vector<vector<char>>& board) {
        // find the next empty cell
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // empty cell found, so we try putting each number one by one
                    for (char c = '1'; c <= '9'; c++) {
                        // check if the current number can be put safely in the empty cell
                        if (isValid(board, i, j, c)) {
                            // if yes, place the number in the sudoku
                            board[i][j] = c;
                            // then call solver to recursivley fill the next empty cell
                            bool res = solver(board);

                            // if a valid solution is found with the current number, return true
                            if (res)
                                return true;
                            // otherwise backtrack by removing the number so that the next number can be checked
                            else
                                board[i][j] = '.';
                        }
                    }
                    // no number was valid in the current empty cell, so we return false
                    return false;
                }
            }
        }
        // no empty cell was found, hence sudoku has been solved. so, return truei
        return true;
    }

    // Master function to solve a a sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}