#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// https://youtu.be/nv7F4PiLUzo

class Solution {
   public:
    // The logic used here is similar to "Median of two sorted Arrays".
    // We have to take "mid1" elements from arr1 and "mid2" elements from arr2 such that
    // they form the first 'k' elements of the merged sorted array. The max of the 'k' elements will be the result.
    int kthElement(int arr1[], int arr2[], int n1, int n2, int k) {
        // make sure that arr1 is the smaller one ( for better time complexity)
        if (n1 > n2)
            return kthElement(arr2, arr1, n2, n1, k);

        // We choose low and high such that 'mid1' & 'mid2' will be a value that will result to total 'k' elements.
        int low = max(0, k - n2), high = min(n1, k);

        // Then we perform binary search to find the valid 'mid1'
        while (low <= high) {
            // Calculate midpoints in both arrays based on 'k'
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;

            // Initialize variables to default for edge cases( no elements on left partition from arr1 etc)
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            // Get elements to the right of midpoints
            if (mid1 < n1) r1 = arr1[mid1];
            if (mid2 < n2) r2 = arr2[mid2];

            // Get elements to the left of midpoints
            if (mid1 > 0) l1 = arr1[mid1 - 1];
            if (mid2 > 0) l2 = arr2[mid2 - 1];

            // Check if the current partition is the correct one
            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if (l1 > r2)
                // Move search to the left half if left element of first array is too high
                high = mid1 - 1;
            else
                // Move search to the right half if left element of second array is too low
                low = mid1 + 1;
        }
        return 0;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}