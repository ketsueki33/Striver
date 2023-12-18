#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// https://youtu.be/gYmWHvRHu-s ( mistake in video: Low should be max of the input array, not min)

class Solution {
   public:
    bool tryAllocate(int A[], int N, int M, int k) {
        int count = 1, current = 0;
        for (int i = 0; i < N; i++) {
            if (current + A[i] > k) {
                count++;
                current = A[i];
            } else
                current += A[i];
        }
        return (count <= M);
    }
    // Function to find minimum number of pages.
    //  M->Students N->Books
    int findPages(int A[], int N, int M) {
        if (M > N) return -1;  // If there are more students than the books, then allocations is not possible

        // We will first find the search space. The min of max pages a student can be allocated is the book with max pages.
        // The max of max pages a student can be allocated is the sum of all pages.
        int sum = 0, mx = INT_MIN, res = -1;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            mx = max(mx, A[i]);
        }

        // we assign the low and high values
        int low = mx, high = sum;

        // For each mid in the binary search, we will try to find if we can allocate the books such that the maximum pages a student
        // gets is 'mid'
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // if allocation with 'mid' no. of pages as max is possible, update res and reduce high as we need min of max.
            // so we will check for lower values
            if (tryAllocate(A, N, M, mid)) {
                res = mid;
                high = mid - 1;
            }
            // if allocation not possible, increase 'low'
             else {
                low = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    int n = 7;
    int arr[] = {15,
                 10,
                 19,
                 10,
                 5,
                 18,
                 7};
    int m = 5;
    cout << obj.tryAllocate(arr, n, m, 26);

    return 0;
}