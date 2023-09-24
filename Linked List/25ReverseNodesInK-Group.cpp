#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/reverse-nodes-in-k-group/
// https://www.youtube.com/watch?v=Of0HPkk3JgI 

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // watch the video or do a dry run to understand better. Little complex.
        if (head == NULL || k == 1) return head;

        // since the head of the list will change, dummy->next will always point to the new head
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *curr = dummy, *prev = dummy, *nxt = NULL;

        // counting the total nodes in the list 
        int count = 0;
        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        // start reversing only if there are more than k nodes remaining
        while (count >= k) {
            // setting curr and next before reversing a group
            curr = prev->next;
            nxt = curr->next;
            for (int i = 1; i < k; i++ ) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            count -= k; // decrease count by k 
        }
        return dummy->next;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}