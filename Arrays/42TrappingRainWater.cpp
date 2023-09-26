#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/trapping-rain-water/
// https://youtu.be/m18Hntz4go8?t=1013
class Solution {
   public:
    // optimal apprach using O(1) extra space
    int trap(vector<int>& height) {
        int n = height.size();

        // this approach uses two pointers 'left' and 'right'
        int left = 0, right = n - 1;

        // leftMax is the max element encountered by 'left'.
        // rightMax is the max element encountered by 'right'.
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int water = 0;

        // we iterate till left and right don't cross each other 
        while (left <= right) {
            // watch video for better understanding
            // if we go inside this condition we are guaranteed that a bulding greater or equal to leftMax exists on
            // the right, because to reach this current 'left' which exists after the 'leftMax', 'left' would have 
            // had to cross the index of leftMax. And to cross that, there should exist a height[right] which is 
            // greater than or equal to left max
            if (height[left] <= height[right]) {
                // add water if height[left] greater than leftMax otherwise update leftMax 
                if (height[left] > leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];
                left++;
            }
            // similarly, if we go inside this condition it is guranteed that a buidling greater than rightMax exists on
            // the left 
            else {
                // add water if height[right] greater than rightMax otherwise update rightMax 
                if (height[right] > rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];
                right--;
            }
        }
        return water;
    }

    // unoptimal approach(better) using O(2n) extra space
    int trap2(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
            rightMax[n - i - 1] = max(rightMax[n - i], height[n - i - 1]);
        }
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    vector<int> height = {4, 2, 0, 3, 2, 5};

    return 0;
}