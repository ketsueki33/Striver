#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559
// https://www.youtube.com/watch?v=R_Mfw4ew-Vo

bool isFeasible(vector<int> stalls, int k, int gap) {
    int placed = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= gap) {
            placed++;
            last = stalls[i];
        }
    }
    if (placed >= k)
        return true;
    else
        return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    // this problem is of the pattern of finding "min of max" or "max of min". Here we have to peform binary search.
    // binary search on what? The question is asking for max of min distance between cows.
    // so our search space will be all the possible distance between cows.

    sort(stalls.begin(), stalls.end());  // sort the array first so that the stalls are in correct order

    // find the search space. The maximun distance between two stalls can be diff btw first and last stall.
    // The min distance between two stalls is the min distance between two consecutive stalls but we have taken 1 for simplicity.
    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
    int res = 0;

    while (low <= high) {
        // calculate mid
        int mid = low + (high - low) / 2;

        // check if cows can be placed with a minimum gap of 'mid'
        if (isFeasible(stalls, k, mid)) {
            // if yes, then update result and increase 'mid' to check for bigger gaps
            res = mid;
            low = mid + 1;
        } else
            // if now, then just decrease 'mid' to check for smaller gaps.
            high = mid - 1;
    }
    return res;
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}