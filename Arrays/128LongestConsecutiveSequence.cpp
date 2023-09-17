#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/longest-consecutive-sequence/
// https://www.youtube.com/watch?v=oO5uLE7EUlM

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // we first store our array inside a hash set. This also removes all duplicates
        unordered_set<int> s(nums.begin(), nums.end());

        // then we iterate over the set. If the current element is the first element of a sequence, then and
        // then only we check for the whole sequence. We update the result when we find a longer sequence.
        int res = 0;
        for (auto x : s) {
            if (!s.count(x - 1)) {  // if x-1 exists, then x is not the first element in the sequence
                int count = 1;
                while (s.count(++x)) {
                    count++;
                }
                res = max(res, count);
            }
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