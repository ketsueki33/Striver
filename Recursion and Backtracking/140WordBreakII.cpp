#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/word-break-ii/
// https://www.youtube.com/watch?v=fNVs1J2KCyo - Trie based solution

class Solution {
   public:
    // recursive function to make word breaks and add sentecnes to the result list
    void findBreaks(vector<string> &res, string s, string currWord, string currSent, int index, unordered_set<string> dict) {
        // if we have checked the whole sentence, return.
        if (index == s.size()) {
            // remove the empty space in the beginning of the sentence
            currSent.erase(0, 1);

            //  push the currSent only if the currWord is empty. If currWord is not empty, it would mean the sentence
            // didn't end with a valid word.
            if (currWord == "")
                res.push_back(currSent);
            return;
        }

        // add the current char to the current word
        currWord += s[index];

        // check if the current word is a valid word
        if (dict.count(currWord)) {
            // if yes, then recusively call the function to find the next break by adding current word to current sentence
            // and set current word as empty
            findBreaks(res, s, "", currSent + " " + currWord, index + 1, dict);
        }
        // keep on continuing with the current word to find the next valid break. currSent remains unchanged
        // we do this even if currWord is a valid word as this word could be a part of other valid words. Eg) "cat" and "cats"
        findBreaks(res, s, currWord, currSent, index + 1, dict);
    }

    // Master function to find all valid sentences
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        // storing the valid words in a hash set
        // NOTE:- trie can be used instead of a hash set to optimize the code
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // initialising a list of strings to store all the valid sentences
        vector<string> res;

        findBreaks(res, s, "", "", 0, dict);
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
