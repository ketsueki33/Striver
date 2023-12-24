#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.interviewbit.com/problems/maximum-sum-combinations/
// https://www.youtube.com/watch?v=yNLu2kJUjjU

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    // Sorting both arrays in ascending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Getting the size of the arrays
    int n = A.size();

    // Priority queue to store pairs of sum and its indices
    // Max heap is used to get the maximum sum
    priority_queue<pair<int, pair<int, int>>> pq;

    // Set to store pairs of indices to avoid duplicates
    set<pair<int, int>> s;

    // Pushing the maximum sum and its indices into the priority queue
    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});

    // Add the selected indices to the set
    s.insert({n - 1, n - 1});

    // Vector to store the result
    vector<int> res;

    // Loop until C becomes zero
    while (C--) {
        // Get the maximum sum and its indices
        auto top = pq.top();
        pq.pop();

        // Push the maximum sum into the result vector
        res.push_back(top.first);

        // Get the indices of the maximum sum
        int l = top.second.first;
        int r = top.second.second;

        // Try to push the sum of the next largest element from A and the current element from B into the priority queue
        if (l > 0 && !s.count({l - 1, r})) {
            pq.push({A[l - 1] + B[r], {l - 1, r}});
            s.insert({l - 1, r});
        }

        // Try to push the sum of the current element from A and the next largest element from B into the priority queue
        if (r > 0 && !s.count({l, r - 1})) {
            pq.push({A[l] + B[r - 1], {l, r - 1}});
            s.insert({l, r - 1});
        }
    }

    // Return the result vector
    return res;
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}