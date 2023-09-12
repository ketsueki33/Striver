#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://www.youtube.com/watch?v=excAOvwF_Wk

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // intialise an element to keep track of the max element so far from the end
        int greatestSoFar = prices[n - 1];
        int res = 0;

        // we use the fact that the day on which we buy will always be before the day we sell
        // we iterate right to left and keep updating the max element as well as the profit
        for (int i = n - 2; i >= 0; i--) {
            res = max(res, greatestSoFar - prices[i]);
            greatestSoFar = max(greatestSoFar, prices[i]);
        }
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