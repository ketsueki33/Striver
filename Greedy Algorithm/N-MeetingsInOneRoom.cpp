#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// https://www.youtube.com/watch?v=II6ziNnub1Q

class Solution {
   public:
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int> > meet;
        for (int i = 0; i < n; i++) {
            meet.push_back(make_pair(end[i], start[i]));
        }

        // sort all meetings in order of their end times
        sort(meet.begin(), meet.end());

        // initialise count as 1 as the first meeting with the least end time is always part of the solution
        // lastPicket to keep track of the last selected meeting
        int count = 1, lastPicked = 0;

        // iterate through the remaining meetings
        for (int i = 1; i < n; i++) {
            // if the current meeting doesn't overlap with the last picked meeting
            if (meet[i].second > meet[lastPicked].first) {
                // increase count and set the current meeting as last picked
                count++;
                lastPicked = i;
            }
        }
        return count;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}