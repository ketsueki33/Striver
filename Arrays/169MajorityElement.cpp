#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/majority-element/
// https://www.youtube.com/watch?v=nP_ns3uSh80

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // Boyer-Moore's voting algorithm is used which works in two phases:

        // 1. First phase finds the possible candidate to become the majority element. It works by keeping track of
        // current major element till now and the count of it. If the next element is same as major element, we
        // increase the count, otherwise we decrease it. If count becomes zero, we set the current element as
        // the major element and set it's count as 0.

        // 2. Second phase checks if the candidate found by the first phase is the majority element or not. If
        // it is not then, then no other majority element exists and return -1.

        // First Phase
        int currMaj = 0, count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[currMaj] == nums[i])
                count++;
            else
                count--;
            if (count == 0) {
                count = 1;
                currMaj = i;
            }
        }

        // Second phase
        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == nums[currMaj])
                count++;
        }
        if (count >= (n / 2))
            return nums[currMaj];
        else
            return -1;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}