#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/873366
// https://www.youtube.com/watch?v=2D0D8HE6uak

pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    // we calculate the sum and sum of squares of the array elements
    long long actSum = 0, actSquareSum = 0;
    for (auto x : arr) {
        actSum += (long long)x;
        actSquareSum += (long long)x * (long long)x;
    }
    long long calcSum, calcSquareSum;
    calcSum = n * (n + 1) / 2;
    calcSquareSum = calcSum * (2 * n + 1) / 3;
    long long diffSum = calcSum - actSum;
    long long diffSquareSum = calcSquareSum - actSquareSum;
    long long x = ((diffSquareSum / diffSum) + diffSum) / 2;
    long long y = x - diffSum;
    return {(int)x, (int)y};
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int> arr = {1, 2, 4, 4, 3, 5};
    pair<int, int> p = missingAndRepeating(arr, arr.size());
    cout << p.first << endl
         << p.second;
    return 0;
}