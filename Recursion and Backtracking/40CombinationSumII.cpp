#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/combination-sum-ii/
// https://www.youtube.com/watch?v=G1fRTGRxXU8

class Solution {
   public:
    //  recursive function to generate all combinations and check if they are valid
    void findCombination(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int index = 0) {
        // if target is 0, it means the current combination is valid
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        // Iterate through all elements to add it into the combination one by one. Think of this as generating
        // combinations in increasing sizes. First we get all the combinations of size 1, then of size 2 and so on.
        for (int i = index; i < candidates.size(); i++) {
            // Check for duplicate elements and skip them
            // we dont check if i == index as it means it is the first element being considered for a given step
            if (i != index && candidates[i] == candidates[i - 1]) continue;

            // check if current element is not greater than the target
            if (candidates[i] > target) break;

            // include the current element in the combination
            v.push_back(candidates[i]);
            // recurively find combinations with current element added
            findCombination(candidates, target - candidates[i], ans, v, i + 1);
            // Backtrack by removing the last added element to explore other possibilities
            v.pop_back();
        }
    }

    // Master function to find all combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // answer container to store all the valid combinations
        vector<vector<int>> ans;
        // vector to keep track of the current combination
        vector<int> v;
        // sort the input array to handle duplicate elements
        sort(candidates.begin(), candidates.end());

        findCombination(candidates, target, ans, v, 0);
        return ans;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}