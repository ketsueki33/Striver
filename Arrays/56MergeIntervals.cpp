#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/merge-intervals/
// https://www.youtube.com/watch?v=IexN60k62jo

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // we first sort the intervals to bring the intervals with similar start point together
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        // start and end to keep track of the  ongoing interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // loop to go through all intervals
        for (int i = 1; i < intervals.size(); i++) {
            int newStart = intervals[i][0], newEnd = intervals[i][1];
            // update the ongoing inverval if there is overlap
            if (newStart <= end) {
                if (newEnd > end) end = newEnd;
            }  // if the current and ongoing dont overlap, push ongoing and update it with current interval
            else {
                res.push_back({start, end});
                start = newStart;
                end = newEnd;
            }
        }
        res.push_back({start, end});
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    Solution obj;
    vector<vector<int>> intervals = {{1, 4}, {0, 1}, {-15, -10}, {3, 7}, {10, 12}};
    vector<vector<int>> asn = obj.merge(intervals);
    for (auto x : asn) {
        cout << "[" << x[0] << "," << x[1] << "]" << endl;
    }

    return 0;
}