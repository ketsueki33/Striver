#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/add-two-numbers/
// https://www.youtube.com/watch?v=LBVsXSMOIk4

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // create a dummy node to to start making a linked list
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy; //curr to keep track of current node
        int carry = 0; // initialize carry as 0

        // iterate while we have an element to add
        while (l1 != NULL || l2 != NULL || carry == 1) {
            int sum = carry;

            if( l1 != NULL ){
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2 != NULL ){
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = temp;
            curr = curr->next;
        }
        // the node next of dummy is the head node
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
