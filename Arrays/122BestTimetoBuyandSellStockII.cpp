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

        // if pocket true, we have bought and are ready to sell. If false, we can buy.
        bool pocket = false;

        // cost keeps track of the price of last bought stock
        int profit = 0, cost;

        // We buy at dip ( currElement < nextElement). We sell at peak ( currElement > nextElement)
        for (int i = 0; i < n - 1; i++) {
            if (!pocket) {
                if (prices[i] < prices[i + 1]) {
                    pocket = true;
                    cost = prices[i];
                }
            } else {
                if (prices[i] > prices[i + 1]) {
                    pocket = false;
                    profit += prices[i] - cost;
                }
            }
        }

        // this is an edge case where we still have a stock left to sell. This will only happen when the 
        // price was only going down at the end or if we bought the 2nd last stock. In both the cases we
        // just sell it on the last day as prices[n-1] - cost >= 0

        if (pocket) {
            profit += prices[n - 1] - cost;
        }

        return profit;
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