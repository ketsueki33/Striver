#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/reverse-linked-list/
// https://www.youtube.com/watch?v=iRtLEoL-r-g

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        // Iterative Solution:-

        ListNode* curr = head , *prev = NULL;

        while( curr != NULL ){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }
        return prev;


        // Recursive Solution :-

        // if( !head || !head->next ) return head;
        // ListNode *rest = reverseList( head->next );
        // head->next->next = head;
        // head->next = NULL;
        // return rest;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}