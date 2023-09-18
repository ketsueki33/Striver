#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// https://www.youtube.com/watch?v=frf7qxiN2qU

class Solution {
   public:
    int maxLen(vector<int>& A, int n) {
        // we solve this by iterating and storing the sum till now( prefix sum) and the index in the hash map
        // at every first step, we first check if the sumTillNow already exists in the map. If it does,
        // this means that the subarray from that point till current index is a a subarray with sum 0
        // we update the result if the subarray length is greater than result
        unordered_map<int, int> mp;
        mp[0] = -1;  // if we have sumTillNow = 0 at any point, then we need to count the whole array till 'i'
        int res = 0, sumTillNow = 0;

        for (int i = 0; i < n; i++) {
            sumTillNow += A[i];
            if (mp.count(sumTillNow)) {
                res = max(res, i - mp[sumTillNow]);
            } else {
                mp[sumTillNow] = i;
            }
        }
        return res;

        // if the input array has only non-negative integers, then it is better to use two pointer approach.
        // we keep track of sum of elements between high and low. we increase high if sum < target.
        // increase low if sum > target. Count when sum == target.
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}