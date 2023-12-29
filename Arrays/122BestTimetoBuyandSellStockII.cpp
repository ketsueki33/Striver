#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// DP solution ( https://www.youtube.com/watch?v=nGJmxkUJQGs )

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // res to keep track of accumulated profits
        int res = 0;

        // we will use the fact that we are allowed to sell and buy on the same day
        // so at every index, we assume that we could have bought the stock of the previous day.

        for (int i = 1; i < n; i++)
            // if there is a spike, we sell the stock bought on the previous day.
            if (prices[i] > prices[i - 1])
                res += (prices[i] - prices[i - 1]);
        // if there is a dip, swe move to the next day.

        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int> prices = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution obj;
    cout << obj.maxProfit(prices);

    return 0;
}