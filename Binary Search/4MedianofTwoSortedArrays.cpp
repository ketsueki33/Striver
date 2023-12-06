#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://youtu.be/F9c7LpRZWVQ

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // see video for better understanding

        // Check if we need to swap the vectors for efficiency
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2) return findMedianSortedArrays(b, a);

        // Calculate required elements in the left partition for median
        int reqLeft = (n1 + n2 + 1) / 2;

        // Define search boundaries for left partition in first array
        int low = 0, high = n1;
	// For further optimization:
	// int low = max(0,reqLeft - n2 -1 ), high = min(n1, reqLeft);

        // Total number of elements
        int n = n1 + n2;

        // Binary search to find the correct partition
        while (low <= high) {
            // Calculate midpoints in both arrays based on required left element
            int mid1 = (low + high) >> 1;
            int mid2 = reqLeft - mid1;

            // Initialize variables to store elements around the midpoints
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            // Get elements to the right of midpoints
            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];

            // Get elements to the left of midpoints
            if (mid1 > 0) l1 = a[mid1 - 1];
            if (mid2 > 0) l2 = b[mid2 - 1];

            // Check if the current partition is the correct one
            if (l1 <= r2 && l2 <= r1) {
                // Check if even or odd number of elements
                if (n % 2 == 1) {
                    // Return the maximum of left elements
                    return max(l1, l2);
                } else {
                    // Return the average of maximum left and minimum right elements
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                }
            } else if (l1 > r2) {
                // Move search to the left half if left element of first array is too high
                high = mid1 - 1;
            } else {
                // Move search to the right half if left element of second array is too low
                low = mid1 + 1;
            }
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
