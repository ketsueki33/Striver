#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// https://youtu.be/37E9ckMDdTk?t=1902

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // 'k' stores the index of the last unique element enocuntered
        int k = 0;

        // we iterate through the array
        for (int i = 0; i < n; i++) {
            // if we find an element which is not equal to the last unique element
            if( nums[i] != nums[k] ){
                // increment 'k' and store the new unique element at 'k'.
                k++;
                nums[k] = nums[i];
            }
        }

        // k+1 will the number of unique elements preseent in the array
        return k+1;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}