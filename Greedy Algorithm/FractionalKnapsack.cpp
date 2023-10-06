#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// https://www.youtube.com/watch?v=F_DDzYnxO14

struct Item {
    int value;
    int weight;
};

class Solution {
   public:
    // Custom comparison function to sort items by their value-to-weight ratio in descending order.
    static bool myCmp(Item a, Item b) {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sort the items by their value-to-weight ratio in descending order.
        sort(arr, arr + n, myCmp);

        double res = 0;
        int rem = W;

        // Iterate through the sorted items to fill the knapsack.
        for (int i = 0; i < n; i++) {
            int currWeight = arr[i].weight;

            // If the current item can fit entirely in the remaining capacity of the knapsack.
            if (currWeight <= rem) {
                res += arr[i].value;  // Add the entire value of the item.
                rem -= currWeight;    // Reduce the remaining capacity.
            } else {
                // If the current item can only be partially added to the knapsack.
                // Add a fraction of the item's value.
                res += (arr[i].value / (double)arr[i].weight) * (double)rem;
                break;  // Stop the loop as the knapsack is now full.
            }
        }

        return res;  // Return the total value obtained from the knapsack.
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}