#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
   public:
    // Bucket sort based solution.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count the occurence of each element in the given array
        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;

        // Then instead of inserting the count into a heap, we create another a vector of vectors of size (n+1)
        // n is the orignal array size. We will insert the elements into this vector based on their frequency count.
        // Eg) index 5 will have all elements of frequency 5.
        // Note.. since the size of array is 'n', an element can appear at max 'n' times. ( all the elements are same)

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto x : mp)
            bucket[x.second].push_back(x.first);

        // Then we will traverse our vector of vectors from the end..and find the k most occuring element
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0 && k > 0; i--) {
            for (int x : bucket[i]) {
                res.push_back(x);
                k--;
                if (k == 0)
                    break;
            }
        }
        return res;
    }

    // Heap based solution where you count occurence of each element. Then put the count and element in a heap.
    // Then extract the top K elements from heap.
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto x : nums) {
            mp[x]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto x : mp)
            pq.push({x.second, x.first});

        vector<int> res;

        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
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