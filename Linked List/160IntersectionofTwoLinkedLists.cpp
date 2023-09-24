#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/intersection-of-two-linked-lists/
// https://www.youtube.com/watch?v=u4FWXfgS8jw

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unoptimal approach is to use a hashmap and store all nodes in listA and then traverse listB and compare.

        // optimal approach:-
        // create two dummy nodes to traverse listA and listB.
        // when one reaches the end, move it to the head of the other list.
        // doing this, at one point both the dummies will be equidistant from the intersection.
        // keep iterating till they are equal. This node will be the intersection node.
        // if there is no intersection node, then both dummies will be NULL at the same time, and we will return NULL.

        if( !headA || !headB ) return NULL;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}