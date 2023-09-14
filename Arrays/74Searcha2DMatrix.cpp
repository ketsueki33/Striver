#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        // we will treat the 2D matrix as one big 1D array (flattening it) and performing binary search on it
        // the index of the bottom rightmost element in the matrix will be the highest index
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // converting mid to matrix co-ordinates
            int row = mid/m; 
            int column = mid%m;
            int midElement = matrix[row][column];

            if( target == midElement )
                return true;
            else if ( target < midElement )
                high = mid - 1;
            else 
                low = mid + 1;
        }

        return false;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60},
                                  {75, 80, 90, 100}};
    int target = 90;
    cout << target << endl;
    cout << obj.searchMatrix(matrix, target);
    return 0;
}