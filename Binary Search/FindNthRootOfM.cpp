#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/1062679
// https://www.youtube.com/watch?v=WjpswYrS2nY

// Function to check the suitability of the mid value as a potential nth root of m
int check(int mid, int n, int m) {
    long long ans = 1;

    // Calculating mid to the power of n
    for (int i = 0; i < n; i++) {
        ans = ans * mid;
        // If the calculated value exceeds m, mid is too large, return 2 (indicating high)
        if (ans > m)
            return 2;
    }

    // If the calculated value matches m, mid is the required nth root, return 1 (indicating success)
    if (ans == m)
        return 1;

    // If none of the conditions met, mid is too small, return 0 (indicating low)
    return 0;
}

// Function to find the nth root of m
int NthRoot(int n, int m) {
    int low = 1, high = m;

    // Binary search to find the nth root within the given range
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = check(mid, n, m);

        // Adjusting the search range based on the check result
        if (res == 2)
            high = mid - 1;  // Mid is too high, adjust the upper limit
        else if (res == 0)
            low = mid + 1;  // Mid is too low, adjust the lower limit
        else
            return mid;  // Mid is the nth root, return mid as the result
    }

    // If the nth root is not found within the range, return -1 (indicating failure)
    return -1;
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}