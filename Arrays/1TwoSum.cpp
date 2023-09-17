#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/two-sum/
// https://www.youtube.com/watch?v=UXDSeD9mN-k

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // we are solving this by using hash map. This can also be solved by two pointer approach after sorting.
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i]) > 0) {
                res.push_back(i);
                res.push_back(mp[target - nums[i]]);
                break;
            }
            mp.insert({nums[i], i});
        }
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