#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/permutations/
// https://youtu.be/f2ic2Rsc9pU

class Solution {
   public:
    // Recursive function to generate permutations of 'nums'
    void makePermutations(vector<vector<int>>& res, vector<int>& nums, int index) {
        // If 'index' reaches the end of 'nums', a new permutation is found, so add it to the result.
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }

        // Iterate through the elements starting from 'index'
        for (int i = index; i < nums.size(); i++) {
            // Swap the current element with the element at 'index'
            swap(nums[i], nums[index]);

            // Recursively generate permutations for the rest of the elements
            makePermutations(res, nums, index + 1);

            // Backtrack to the original order by swapping back
            swap(nums[i], nums[index]);
        }
    }

    // Master function to find all permutations of 'nums'
    vector<vector<int>> permute(vector<int>& nums) {
        // initialize a result container for storing permutations
        vector<vector<int>> res;
        makePermutations(res, nums, 0);  // Start generating permutations from the beginning (index 0)
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}