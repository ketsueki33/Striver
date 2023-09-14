#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/powx-n/
// https://www.youtube.com/watch?v=l0YC3876qxg

class Solution {
   public:
    double myPow(double x, int n) {
        long nn = n;
        double ans = 1.0;
        if (n < 0) nn *= -1;  // converting nn to a positive if it was negative

        // we will solve this inside the while loop by taking two cases:
        //  1. nn is even: square x and divide nn by 2
        //  2. nn is odd: multiply ans with x and reduce nn by 1.
        // this will stop when nn reaches 0
        while (nn) {
            if (nn % 2 == 0) {
                x *= x;
                nn /= 2;
            } else {
                ans *= x;
                nn--;
            }
        }
        if (n < 0)  // taking reciprocal if n was negative
            ans = (double)1.0 / (double)ans;
        return ans;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}