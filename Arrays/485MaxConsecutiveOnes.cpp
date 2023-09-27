#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/max-consecutive-ones/
// https://youtu.be/bYWLJb3vCWY?t=1135

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;     // Initialize a variable to count consecutive ones
        int maxCount = 0;  // Initialize a variable to store the maximum count

        for (int x : nums) {
            // If the current element is 1 (represents a consecutive one)
            if (x == 1) {
                count++;                          // Increment the count of consecutive ones
                maxCount = max(maxCount, count);  // Update the maximum count if needed
            } else {
                // If the current element is not 1 (breaks the consecutive sequence)
                count = 0;  // Reset the count to zero
            }
        }

        return maxCount;  // Return the maximum count of consecutive ones
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}