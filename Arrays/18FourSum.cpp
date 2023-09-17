#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

//  https://leetcode.com/problems/4sum/
// https://www.youtube.com/watch?v=eD95WRfh81c

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        // we will use 4 pointers but keep two of them constant to make it like 2 pointer approach
        // two outer loops will set i and j so inside that we can use 2 pointer approach with k and l
        sort(nums.begin(), nums.end());  // sorting is important for this

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // so that i values are not repeated
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // so that j values are not repeated
                int k = j + 1, l = n - 1;
                while (k < l) {               // k and l should not cross ( to prevent overflow )
                    long long sum = nums[i];  // to prevent overflow we add nums[.] one by one
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});  // target matches and we push in res
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;  // prevent duplicate nums[k]
                        while (k < l && nums[l] == nums[l + 1]) l--;  // prevent duplicate nums[l]
                    } else if (sum < target) {
                        k++;  // sum < target so we increase k to get higher sum

                    } else {
                        l--;  // sum > target so we decrease l to get lower sum
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    obj.fourSum(nums, 5);

    return 0;
}