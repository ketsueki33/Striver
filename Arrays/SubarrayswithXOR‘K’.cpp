#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258
// https://youtu.be/eZr-6p0B7ME?t=539

int subarraysWithSumK(vector<int> a, int b) {
    int n = a.size();

    // the solution is similar to subarray with 'k' sum.
    // here, we store xorTillNow and the no. of times it has appeared, in the hashmap.
    // we calculate x which is xorTillNow ^ b . If this x is in the hashmap, it means that the subarray after
    // x till current element is a subarray with XOR b. So we add the count of x to result.
    unordered_map<int, int> mp;
    int count = 0, xorTillNow = 0;
    mp[0] = 1;  // in the start, xorTillNow = 0 , so make its count as 1.

    for (int i = 0; i < n; i++) {
        xorTillNow = (xorTillNow ^ a[i]);
        int x = (xorTillNow ^ b);

        count += mp[x];
        mp[xorTillNow]++;  // update this count in every iteration
    }
    return count;
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    cout << (4 ^ 2);

    return 0;
}