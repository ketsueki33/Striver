#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/reverse-pairs/
// https://www.youtube.com/watch?v=0e4bZaP3MDI

class Solution {
    int merge(vector<int> &nums, int low, int mid, int high) {
        int n1 = mid - low + 1, n2 = high - mid;
        int left[n1], right[n2];

        for (int i = 0; i < n1; i++) left[i] = nums[low + i];
        for (int i = 0; i < n2; i++) right[i] = nums[mid + i + 1];

        // In count inversions, the counting was implemented during merging itself.
        // here, the counting is done before the merging step.
        // the 'r' element keeps track of elements to be included in counting
        // we dont have to count 'r' for every 'i' since arr[i] > 2* arr[r-1] always as the two arrays are
        // sorted and arr[i] keeps increasing and all the elements to be included stay same.
        int r = 0, count = 0;
        for (int i = 0; i < n1; i++) {
            while (r < n2 && (long long)left[i] > (long long)(2LL * right[r])) { // 2LL for preventing overflow
                r++;
            }
            count += r;
        }

        int i = 0, j = 0, k = low;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
                k++;
            } else {
                nums[k] = right[j];
                j++;
                k++;
            }
        }
        while (i < n1) {
            nums[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            nums[k] = right[j];
            j++;
            k++;
        }
        return count;
    }

    int mergeSort(vector<int> &nums, int low, int high) {
        // the counting is implemented in the merge function
        int count = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            count += mergeSort(nums, low, mid);
            count += mergeSort(nums, mid + 1, high);
            count += merge(nums, low, mid, high);
        }

        return count;
    }

   public:
    int reversePairs(vector<int> &nums) {
        // this problem is similar to count inversions so here also we will use merge sort
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    vector<int> nums = {1, 5, 23, 20, 100, 90, 25, 4, 2};
    Solution obj;
    cout << obj.reversePairs(nums) << endl;
    for (auto x : nums) {
        cout << x << endl;
    }
    return 0;
}