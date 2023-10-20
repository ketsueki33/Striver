#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/subsets-ii/
// https://youtu.be/RIn3gOkbhQE

class Solution {
   public:
    // Function to recursively generate subsets
    void findSubsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int index = 0) {
        // Push the current subset into the result list
        res.push_back(subset);

        // Iterate through the elements, starting from the given index
        for (int i = index; i < nums.size(); i++) {
            // Check for duplicate elements and skip them
            // we dont check if i == index as it means it is the first element being considered for a given step
            if (i != index && nums[i] == nums[i - 1])
                continue;

            // Include the current element in the subset
            subset.push_back(nums[i]);

            // Recursively find subsets with the current element included
            findSubsets(nums, res, subset, i + 1);

            // Backtrack by removing the last added element to explore other possibilities
            subset.pop_back();
        }
    }

    // Master function to find all subsets with duplicates removed
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // Initialize a list to store all the valid subsets
        vector<vector<int>> res;
        vector<int> subset;

        // Sort the input nums array to handle duplicates
        sort(nums.begin(), nums.end());

        // Find and collect subsets
        findSubsets(nums, res, subset);

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