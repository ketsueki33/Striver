#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/middle-of-the-linked-list/
// https://www.youtube.com/watch?v=VNf6VynfpdM

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        // we define a slow and fast pointer. Fast pointer moves 2 at a time while slow moves one at a time.
        // whenever fast reaches the end, the node that slow pointer is at is the middle point.
        ListNode* fast=head, *slow = head;
        while( fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}