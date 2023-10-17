#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/combination-sum/
// https://www.youtube.com/watch?v=OyZFFqQtu98 - 2nd Solution

class Solution {
   public:
    void findCombination(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int index) {
        // if target is 0 , it means we have found one of the combinations
        if (target == 0) {
            // push the combination to the answer and return as we don't need to add more candidates in this combination
            ans.push_back(v);
            return;
        }
        // if target is less than 0 , it means the current combination is invalid. So we return
        if (target < 0) {
            return;
        }

        // we iterate through all the possible candidates. candidates before 'index' are not considered
        for (int i = index; i < candidates.size(); i++) {
            // we push the current candidate into the combination
            v.push_back(candidates[i]);
            // we proceed with the combination while reducing the target after adding a candidate
            findCombination(candidates, target - candidates[i], ans, v, i);
            // we remove the current candidate from the combination before proceeding further
            v.pop_back();
        }
    }

    void findCombination2(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int index) {
        // If we've checked all candidates and the target is reduced to 0, add the current combination to the answer.
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(v);  // Add the combination to the answer.
            }
            return;
        }

        // Try including the current candidate if its value is less than or equal to the remaining target.
        if (candidates[index] <= target) {
            // Include the candidate in the current combination.
            v.push_back(candidates[index]);
            // Recursively check with the reduced target.
            findCombination2(candidates, target - candidates[index], ans, v, index);
            // Backtrack: Remove the last added candidate for exploring other possibilities.
            v.pop_back();
            
        }

        // Move on to the next candidate without including the current one.
        findCombination2(candidates, target, ans, v, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
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