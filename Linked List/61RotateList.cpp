#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/rotate-list/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        // counting the length of the linked list 
        ListNode* curr = head;
        int n = 1;
        while (curr->next != NULL) {
            n++;
            curr = curr->next;
        }

        // if k is more than n, then it is same as rotating k % n times
        k = k % n;
        if (k == 0) return head;

        // we attach the tail to the head to make it a circular linked list
        curr->next = head;

        // we need to move n-k nodes the tail
        k = n - k;
        while (k--) {
            curr = curr->next;
        }

        // make the next node the head and break the link
        head = curr->next;
        curr->next = NULL;

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