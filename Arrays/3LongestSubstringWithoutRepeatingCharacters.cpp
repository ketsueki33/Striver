#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://www.youtube.com/watch?v=qtVh-XEpsJo

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // we solve this using two pointer approach. Hashmap is to store the indexes of element btw low and high
        unordered_map<char, int> mp;
        int low = 0, high = 0, longest = 0;

        // we iterate till high < n
        while (high < n) {
            char ch = s[high];

            // we only count if current element isn't in the hashmap or it's index is less that low, coz that would
            // mean that it's in the current subarray and it is repeating. 
            if (!mp.count(ch) || mp[ch] < low) {
                mp[ch] = high; // update the latest appearance of the element
                longest = max(longest, high - low + 1);
                high++;
            } else { // we found a repeating char in the subarray
                low = mp[ch] + 1; // jump to the index after the previous appearance of repeated element
            }
        }
        return longest;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}