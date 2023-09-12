#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

//https://leetcode.com/problems/set-matrix-zeroes/description/
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        // we mark the rows and columns for setting 0s in the first column and row itself
        // the [0][0] spot is in both, so we use one extra variable for the row marker
        int ext = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // marking the column
                    matrix[i][0] = 0;

                    // marking the row
                    if (j == 0)
                        ext = 0;
                    else
                        matrix[0][j] = 0;
                }
            }
        for (int i = n - 1; i > 0; i--)
            for (int j = m - 1; j > 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        if (matrix[0][0] == 0) {
            for (int j = 1; j < m; j++)
                matrix[0][j] = 0;
        }
        if (ext == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}