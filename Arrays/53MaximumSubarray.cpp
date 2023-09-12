#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/maximum-subarray/
// https://www.youtube.com/watch?v=AHZpyENo7k4

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // This problem can be solved using Kadane's Algorithm
        // We calculate the maximum sum subarray ending at every index

        int n = nums.size();
        vector<int> maxEnd(n, -1);
        maxEnd[0] = nums[0];
        int res = nums[0];

        // at every index we have 2 choices
        //      1. continue with the previous subarray
        //      2. disconnect and start a new subbaray
        for (int i = 1; i < n; i++) {
            maxEnd[i] = max( nums[i] , nums[i]+ maxEnd[i-1]);
            res = max( res , maxEnd[i] );
        }
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution obj;
    cout<<obj.maxSubArray(nums);
    return 0;
}