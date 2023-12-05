#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://youtu.be/r3pMQ8-Ad5s

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // the logic we will use with binary search is that for every 'mid', either left half will be sorted or right half
        // will be sorted. Once we determine which half is sorted, we can determine whether the target can be inside the
        // sorted half. We then adjust the 'high' and 'low' accordingly.
        // Note:- both halfs can be sorted if the array is not rotated. But it will still work as we need just
        // one half to be sorted to eliminate halfs.

        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // target is equal to mid.. so return it
            if (nums[mid] == target) return mid;

            // check if left half is sorted
            if (nums[low] <= nums[mid]) {
                // left half is sorted
                if (target >= nums[low] && target < nums[mid])
                    // target is in the sorted left half
                    high = mid - 1;
                else
                    // target is in the unsorted right half
                    low = mid + 1;
            } else {
                // right half is sorted
                if (target > nums[mid] && target <= nums[high])
                    // target is in the sorted right half
                    low = mid + 1;
                else
                    // target is in the unsorted left half
                    high = mid - 1;
            }
        }
        // target not found, return -1
        return -1;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    cout << 11 % 7;

    return 0;
}