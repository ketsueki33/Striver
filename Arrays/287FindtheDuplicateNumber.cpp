#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/find-the-duplicate-number/
// https://www.youtube.com/watch?v=32Ll35mhWg0&embeds_referring_euri=https%3A%2F%2Ftakeuforward.org%2F&feature=emb_imp_woyt

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        // we will use Floyd's cycle detection algo from Linked Lists to solve this
        // intitialise a fast and slow pointer to the first element of array
        int fast = nums[0], slow = nums[0];

        // do-while is necessary as the while loop needs to be executed once since fast and slow are pointing to
        // the same element at the start. Move fast ptr 2 elements at a time and slow pts 1 element at a time.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        // now move one ptr to the first element and move both ptrs one element at a time. 
        // the point where they are equal will give us the duplicate element.
        fast = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;

    vector<int> nums = {1, 3, 4, 2, 2}   ;
    cout << obj.findDuplicate(nums);
    return 0;
}