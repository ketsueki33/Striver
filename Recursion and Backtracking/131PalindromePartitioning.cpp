#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/palindrome-partitioning/
// https://www.youtube.com/watch?v=WBgsABoClE0

class Solution {
   public:
    void findPartition(string s, vector<string>& path, vector<vector<string>>& res, int index = 0) {
        // if we reach the end, it means the current selection of words / partitions is a valid solution
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        // iterate through all the elements to check all substrings starting from 'index' 
        for (int i = index; i < s.size(); i++) {
            // use the utility function to check if current substring is a palindrome
            if (isSubstringPalindrome(s, index, i)) {
                // if it is a palindrome, push the current substring into the result container
                path.push_back(s.substr(index, i - index + 1));

                // recursively find the next partitions by passing 'i+1' as initial index
                findPartition(s, path, res, i + 1);

                // backtrack by removing the last added word/partion to check for other possibilities
                // eg) if we have checked "a|abcb", we also have to check "aa|bcb"
                path.pop_back();
            }
        }
    }

    // Master function to find all the valid partitions
    vector<vector<string>> partition(string s) {
        // container to store all the combinations of valid partitions
        vector<vector<string>> res;
        // vector to store the ongoing words
        vector<string> path;
        findPartition(s, path, res);
        return res;
    }

    // utility function to check if a substring is a palindrome
    bool isSubstringPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}
