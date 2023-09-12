#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// https://leetcode.com/problems/pascals-triangle/

#define pb push_back

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.pb({1});
        if (numRows == 1) return res;
        res.pb({1, 1});
        for (int i = 3; i <= numRows; i++) {
            vector<int> v(i, 1);
            vector<int> temp = res.back();
            for (int j = 1; j < i - 1; j++) {
                v[j] = temp[j] + temp[j - 1];
            }
            res.pb(v);
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