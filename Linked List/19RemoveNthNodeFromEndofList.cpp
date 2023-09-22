#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// https://www.youtube.com/watch?v=Lhu3MsXZy-Q

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // we maintain two pointers 'ahead' and 'behind'. we will keep 'ahead' n nodes ahead of 'behind'.
        // when ahead reaches the last node, the node next to 'behind' is the node to be removed.
        ListNode* ahead = head;
        while(n--){
            ahead = ahead->next;
        }

        // edge case where the node to be removed is the head of the linked list
        if( ahead == NULL ){
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        ListNode* behind = head;

        // moving ahead and behind one at a time till 'ahead' reaches the last node
        while( ahead->next != NULL  ){
            ahead = ahead->next;
            behind = behind->next;
        }
        ListNode* temp = behind->next;
        behind->next = temp->next;
        delete temp;
        return head;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}