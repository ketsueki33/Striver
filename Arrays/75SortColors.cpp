#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/sort-colors/
// https://www.youtube.com/watch?v=tp8JIuCXBaU

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag algorithm is used here
        int n = nums.size();

        // we initialise three pointers - low, mid and high
        int low = 0, mid = 0, high = n - 1;

        // we arrange the array such that:
        //      - '0' to 'low-1' contains 0's
        //      - 'low' to 'mid-1' contains 1's
        //      - 'mid' to 'high-1' contains the unsorted part
        //      - 'high' to 'n-1' contains 2's

        // we work between 'mid' and 'high' since that region has unsorted elements
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<int> nums = {1, 2, 0};
    obj.sortColors(nums);
    for (auto x : nums) cout << x << " ";
    return 0;
}