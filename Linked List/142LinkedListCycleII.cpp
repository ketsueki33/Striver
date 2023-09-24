#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/linked-list-cycle-ii/
// https://www.youtube.com/watch?v=QfbOhn0WZ88
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd's cycle detection algorithm

        // move slow one node at a time and fast two nodes at a time
        ListNode *slow = head, *fast = head;
        do {
            if( fast == NULL || fast->next == NULL ) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // move slow pointer to the start of the list 
        slow = head;

        // the node where they meet is the node where the cycle starts
        // the idea is that :
        //      'slow' covers - l1 + l2 
        //      'fast' covers - l1 + l2 + n*c 
        //      but fast moves twice the distance of slow so 2( l1 + l2 ) = l1 + l2 + n*c
        //      on simplifying- l1 = n*c - l2 
        //   so on moving the fast by l1 more, we get the starting point
        //  l1 here is the distance from head to the cycle start point 
        //  l2 is the distance from cycle start point to the point where slow and fast met.
        //  n*c is the extra cycles of the loop fast must have taken before meeting slow

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
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