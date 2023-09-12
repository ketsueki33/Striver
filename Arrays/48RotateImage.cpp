#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/rotate-image/
// https://www.youtube.com/watch?v=Z0R2u6gd3GU

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        // the approach is to first transpose the matrix and then reverse each row
        // this gives us the matrix rotated by 90 degrees.

        int n = matrix.size();

        // transposing the matrix
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reversing each row
        for (int i = 0; i < n; i++) {
            vector<int>& currRow = matrix[i];
            reverse(currRow.begin(), currRow.end());
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