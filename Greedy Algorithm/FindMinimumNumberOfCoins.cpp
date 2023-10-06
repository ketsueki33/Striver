#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277
// https://www.youtube.com/watch?v=mVg9CfJvayM

vector<int> MinimumCoins(int val) {
    // Define the denominations of coins available in ascending order.
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;        // Number of denominations.
    vector<int> res;  // Vector to store the result (selected coins).

    // Iterate through denominations from the largest to the smallest.
    for (int i = n - 1; i >= 0; i--) {
        // While the remaining value is greater than or equal to the current denomination.
        while (val >= deno[i]) {
            val -= deno[i];          // Deduct the denomination from the remaining value.
            res.push_back(deno[i]);  // Add the denomination to the result vector.
        }
    }
    return res;  // Return the vector containing the minimum number of coins required.
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}