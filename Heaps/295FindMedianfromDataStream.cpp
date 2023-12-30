#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    // Max heap stores the smaller half of elements
    priority_queue<int> maxHeap;

    // Min heap stores the larger half of elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Balance the heaps after adding a number
    void balance() {
        minHeap.push(maxHeap.top());  // Move the largest element from maxHeap to minHeap
        maxHeap.pop();                // Remove the largest element from maxHeap
    }

    // Correct the heaps if largest of maxHeap is greater than smallest of minHeap
    void correct() {
        int a = maxHeap.top();
        maxHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        minHeap.push(a);
        maxHeap.push(b);
    }

   public:
    MedianFinder() {
    }

    // Add a number to the median finder
    void addNum(int num) {
        maxHeap.push(num);  // Add the number to maxHeap

        // If maxHeap becomes larger than minHeap by more than one, move the top element from maxHeap to minHeap
        if (maxHeap.size() > minHeap.size() + 1)
            balance();

        // If minHeap is not empty and the top element of maxHeap is larger than the top element of minHeap, swap them
        if (!minHeap.empty() && maxHeap.top() > minHeap.top())
            correct();
    }

    // Find the median of the numbers added so far
    double findMedian() {
        // If the sizes of the heaps are equal, the median is the average of the tops of both heaps
        if (maxHeap.size() == minHeap.size())
            return double(maxHeap.top() + minHeap.top()) / 2;
        // Otherwise, the median is the top of maxHeap
        else
            return double(maxHeap.top());
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}