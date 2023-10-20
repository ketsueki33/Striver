#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
// https://youtu.be/rYkfBRtMJr8

class Solution {
   public:
    // recursive function to find all subset sums
    void findSum(vector<int> arr, int n, vector<int> &res, int sum = 0, int index = 0) {
        // if index == n , it means all the elements have been considered
        if (index == n) {
            res.push_back(sum);  // push the sum into result list and return
            return;
        }
        // At every index we have two choice:
        // 1. include the current element in the subset and then move on to the next index
        findSum(arr, n, res, sum + arr[index], index + 1);

        // 2. exclude the current element from the subset and then move on to the next index
        findSum(arr, n, res, sum, index + 1);
    }
    // Master function
    vector<int> subsetSums(vector<int> arr, int n) {
        // initialise a list to store all the possible sums
        vector<int> res;
        findSum(arr, n, res);
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