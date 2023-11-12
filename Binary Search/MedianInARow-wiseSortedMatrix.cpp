#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473
// https://www.youtube.com/watch?v=Q9wXgdxJq48

// Function to find the upper bound index in a sorted vector for a given value x
int upperBound(vector<int> v, int n, int x) {
    int low = 0, high = n - 1;

    // Binary search to find the upper bound index of x
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] <= x)
            low = mid + 1;  // Move the search range to the right
        else
            high = mid - 1;  // Move the search range to the left
    }
    return low;
}

// Function to count the number of elements less than or equal to x in a matrix
int numLessThanOrEqX(vector<vector<int>> &matrix, int m, int n, int x) {
    int count = 0;

    // Loop through each row and calculate the count using upperBound function
    for (int i = 0; i < m; i++) {
        count += upperBound(matrix[i], n, x);  // Calculate count for each row
    }
    return count;
}

// Function to find the median value in a matrix
int median(vector<vector<int>> &matrix, int m, int n) {
    // Initialize high and low to find the range of possible medians
    int high = INT_MIN, low = INT_MAX;

    // Finding the highest and lowest values in the matrix
    for (int i = 0; i < m; i++) {
        high = max(high, matrix[i][n - 1]);  // Get the highest value in the matrix
        low = min(low, matrix[i][0]);        // Get the lowest value in the matrix
    }

    // Calculate the required count for the median
    int req = (n * m) / 2;

    // Binary search to find the median
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Count the number of elements less than or equal to the potential median
        if (numLessThanOrEqX(matrix, m, n, mid) <= req)
            low = mid + 1;  // Move the search range to the right
        else
            high = mid - 1;  // Move the search range to the left
    }
    return low;  // Return the low value as the median
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int> v = {1, 5, 7, 7, 7, 7, 8, 8, 9, 11};
    cout << upperBound(v, v.size(), 0);

    return 0;
}