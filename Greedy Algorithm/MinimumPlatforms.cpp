#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// https://www.youtube.com/watch?v=dxVcMDI7vyI

class Solution {
   public:
    int findPlatform(int arr[], int dep[], int n) {
        // we first sort the arrival and departure arrays
        // the order of appearance of trains doesn't matter here as we dont want to know which train is leaving at a
        // particular time, only the fact that it is leaving matters.
        sort(arr, arr + n);
        sort(dep, dep + n);

        // the first arriving train is included in the result
        int currPf = 1, maxPf = 1;
        int i = 1, j = 0;

        // then we iterate through the remaining trains' arrival and departure
        while (i < n && j < n) {
            // if the current train arrivers before departure of a train
            if (arr[i] <= dep[j]) {
                // increase the count of used platforms and increment the arrival pointer.
                currPf++;
                i++;
            }
            // otherwise the current train is departing before the arrival of a train
            else {
                // decrease the count of used platforms and increment the departure pointer.
                currPf--;
                j++;
            }

            maxPf = max(currPf, maxPf);  // update maxPf if currPf > maxPf
        }

        return maxPf;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}