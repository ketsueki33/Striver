#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/majority-element-ii/
// https://www.youtube.com/watch?v=vwZj1K0e9U8

class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // We apply the same Boyer-Moore's voting algo here like we did in MajorityElement1. But this time we
        // keep track of two candidates instead of one. Here also, there are two phases.
        // We have to make sure cand1 and cand2 are never equal.

        // cand1 and cand2 are set like this to avoid conflicts ( like if they were 0 and array had 0's )
        int cand1 = INT_MIN, cand2 = INT_MAX, count1 = 0, count2 = 0;
        // phase 1
        for (auto x : nums) {
            if (count1 == 0 && x != cand2) {  // we make sure current element is not cand2 before setting cand1
                cand1 = x;
                count1 = 1;
            } else if (count2 == 0 && cand1 != x) {  // check if current element is not cand1 before setting cand2
                cand2 = x;
                count2 = 1;
            } else if (cand1 == x) {
                count1++;
            } else if (cand2 == x) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> res;

        // phase 2
        count1 = 0;
        count2 = 0;
        for (auto x : nums) {
            if (x == cand1) count1++;
            if (x == cand2) count2++;
        }
        if (count1 > n / 3) res.push_back(cand1);
        if (count2 > n / 3) res.push_back(cand2);
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    Solution obj;
    vector<int> nums = {-1, -1, -1};
    vector<int> res = obj.majorityElement(nums);
    for (auto x : res)
        cout << x << endl;

    return 0;
}