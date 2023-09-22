#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/delete-node-in-a-linked-list/
// https://youtu.be/icnp4FJdZ_c

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    void deleteNode(ListNode* node) {
        // it is not possible to delete the node itself without a pointer to the previous node
        // So what we do is copy the value of the next node to the given node
        // and then delete the next node
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}