#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/unique-paths/
// https://www.youtube.com/watch?v=t_f0nwwdg5o

class Solution {
   public:
    int uniquePaths(int m, int n) {
        // to reach the target we will always have to go (m-1) steps right and (n-1) steps down
        // we just have to find the order in which we take these right and down steps
        // i.e finding all the possible arrangements. We will just use the basic formula from PnC.
        //               no. of arrangements of ( x + y ) = (x+y)! / (x!)*(y!)
        //  which is just the formula of  (x+y) C (x) or (x+y) C (y) [ n C r ]
        int N = m + n - 2;
        if (m > n) swap(m, n);
        int r = m - 1;
        double res = 1;

        for (int i = 1; i <= r; i++) {
            res = (res * (N + 1 - i)) / i;
        }

        return int(res);
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    Solution obj;
    cout << obj.uniquePaths(7, 3);

    return 0;
}