#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/single-element-in-a-sorted-array/
// https://youtu.be/PzszoiY5XMQ

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        // we initialise high as n-2 because our answer will be at 'low' in the end. End is when low crosses high.
        // If the last element is the answer, and 'high' is at n-1, then there will be no end.
        int low = 0, high = nums.size() - 2;

        // We will find the breakpoint using binary search. Breakpoint here is the point just before the single element.
        // Ex: 1 1 |breakpt| 2 3 3 4 4 8 8
        // Notice how in the left half, the first instance of an repeating element is at an even index and the second
        // instance is at an odd index.
        // In the binary search, at each step, we will try to determine whether 'mid' is in the left half or right half

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // XOR with 1 will give the previous even index if 'mid' is odd.
            // XOR with 1 will give the next odd index if 'mid' is even.
            // we can use this to check if 'mid' is in the left or right half.
            // because in the left half, nums[odd index] = nums[previous even] and nums[even index] = nums[ next odd ]

            if (nums[mid] == nums[mid ^ 1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[low];
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}