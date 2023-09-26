#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/next-permutation/
// https://www.youtube.com/watch?v=JDOXKqF60RQ

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        // finding the furthest point where a smaller element exists before an greater element
        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                break;
        }
        // edge case where the given permutation is the last permutation possible
        // We just reverse the array as it will give the sorted array
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // replace nums[i] with the smallest element greater than than nums[i] that lies after 'i'
        for (int k = nums.size() - 1; k > i; k--) {
            if (nums[k] > nums[i]) {
                swap(nums[k], nums[i]);
                break;
            }
        }

        // the elements after i will now be be in descending order. Reversing will make this ascending
        // reverse the elements after i to get the permutation right after the given permutation
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    obj.nextPermutation(nums);
    for (auto x : nums)
        cout << x << " ";

    return 0;
}
