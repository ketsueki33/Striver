#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/merge-two-sorted-lists/
// https://youtu.be/Lhu3MsXZy-Q

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        // we make sure that l1->val is smaller than l2->val
        if (l1->val > l2->val) swap(l1, l2);
        // we initialise the head of our result linked list as l1 now we know that it is smaller
        ListNode* head = l1;

        // we iterate till l1 and l2 are not NULL
        while (l1 != NULL && l2 != NULL) {
            ListNode* temp = NULL;  // temp to keep track of previous element
            //  we iterate in l1 till l1->val is less or equal to than l2->val
            while (l1 != NULL && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;  // we break the chain in l1 and connect to l2
            swap(l1, l2);     // we swap again to make l1->val smaller than l2->val
            // if l1 becomes null, temp would be connected to the rest of l2 and the loop will be exited
        }
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
