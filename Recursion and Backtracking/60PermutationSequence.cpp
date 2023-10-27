#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/permutation-sequence/
// https://youtu.be/wT7gcXLYoao

class Solution {
   public:
    // The optimal solution doesn't use recursion actually. We can solve this by just simple iteration.
    string getPermutation(int n, int k) {
        // Initialize a variable to calculate factorials.
        int fact = 1;

        // Create a vector to store numbers from 1 to n.
        vector<int> numbers;

        for (int i = 1; i <= n; i++) {
            // Calculate the factorial of n.
            fact *= i;
            // Store numbers from 1 to n in the vector.
            numbers.push_back(i);
        }

        // Convert k to 0-based indexing.
        k--;

        // Initialize the result string.
        string res = "";

        // stay inside the while loop till 'numbers' is empty
        while (true) {
            // Calculate the factorial of (n-1) in the first iteration, (n-2) in the second, and so on.
            fact = fact / numbers.size();
            // Append the character representation of the selected number to the result.
            res.push_back('0' + numbers[k / fact]);
            // Remove the selected number from the list.
            numbers.erase(numbers.begin() + k / fact);
            // If there are no more numbers left to select, exit the loop.
            if (numbers.size() == 0)
                break;
            // Update k to the remainder when divided by the factorial as k-(k%fact) numbers have been skipped
            k = k % fact;
        }
        return res;  // Return the final result string.
    }
};

// NOTE- Brute force solution is recursion based where we generate all the permutations and sort them
//  and then select the kth permutation.

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}