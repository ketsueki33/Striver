#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/kth-largest-element-in-an-array/
// https://www.youtube.com/watch?v=XEmy13g1Qxc

class Solution {
   public:
    int quickSelect(vector<int>& nums, int l, int r) {
        int pivot = nums[r], ptr = l;
        for (int i = l; i < r; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        swap(nums[ptr], nums[r]);
        return ptr;
    }

    int kthFinder(vector<int>& nums, int l, int r, int k) {
        // call the partition making function which returns the index of pivot
        int qs = quickSelect(nums, l, r);

        // if pivot == k , return nums[pivot]
        if (qs == k)
            return nums[qs];

        // adjust left and right accordinly if pivot != k
        if (qs < k)
            return kthFinder(nums, qs + 1, r, k);
        else
            return kthFinder(nums, l, qs - 1, k);

        return -1;
    }

    // Using Quick Select - TC-> Average(n) , Worst( n^2 )
    // this approach uses the partioning using pivot method from quick sort
    int findKthLargest(vector<int>& nums, int k) {
        // adjust k so that we are looking for kth index in a sorted array
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1;

        // use the utility function
        return kthFinder(nums, l, r, k);
    }

    // Using Max Heap - TC-> O(n + k*log(n))
    int findKthLargest1(vector<int>& nums, int k) {
        // we solve using max heap
        // build a max heap using the given vector
        priority_queue<int> pq(nums.begin(), nums.end());

        // pop (k-1) elements so that kth largets element the root of the max heap
        while (--k) {
            pq.pop();
        }

        // return kth largest element
        return pq.top();
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}