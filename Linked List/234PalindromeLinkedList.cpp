#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/palindrome-linked-list/
// https://youtu.be/-DtNInqFUXs

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    // Approach 1 - if we are not allowed to modify the linked list and we can use extra space:
    bool isPalindrome(ListNode *head) {
        stack<int> st;  // to store the elements till mid point

        // dummy node so that the the slow pointer is at middle for odd size and before middle for even size
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            st.push(slow->val);
            fast = fast->next->next;
        }
        if (fast == NULL) st.pop();  // removing the middle element from stack if the palindrom is odd size
        slow = slow->next;           // pointing slow to next of middle

        // checking if the remaining elements in the list match with the first part
        while (!st.empty()) {
            if (st.top() != slow->val)
                return false;
            st.pop();
            slow = slow->next;
        }
        return true;
    }

    // Approach 2 - if we are not allowed to use extra space - we just reverse after the middle point and the
    // compare the two parts with head and slow. If we are not allowed to modify the linked list, then find
    // the middle point again and reverse the second half again to get the original linked list.

    bool isPalindrome2(ListNode *head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *dummy = head;

        while (slow != NULL) {
            if (dummy->val != slow->val) return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *ptr) {
        ListNode *pre = NULL;
        ListNode *nex = NULL;
        while (ptr != NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = nex;
        }
        return pre;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}