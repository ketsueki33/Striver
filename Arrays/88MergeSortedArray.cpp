#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/merge-sorted-array/
// https://www.youtube.com/watch?v=n7uwj04E0I4

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // we first make sure that each element is the right array
        // compare largest of arr1 with smallest of arr2.Keep swapping till largest(arr1)>smallest(arr2).

        int left = m - 1, right = 0;
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                break;
            }
        }

        // then we sort both the arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    Solution obj;
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {2, 5, 6};
    obj.merge(n1, n1.size(), n2, n2.size());
    for (auto x : n1) {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : n2) {
        cout << x << " ";
    }

    return 0;
}