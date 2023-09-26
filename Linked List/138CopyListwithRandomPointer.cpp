#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://leetcode.com/problems/copy-list-with-random-pointer/
// https://youtu.be/VNf6VynfpdM

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        // unoptimal approach is to create a hashmap where we store the original node's and its copy node's pointer
        // then we just traverse the map and assign next and random using the hashmap.

        if(!head) return head;

        // Optimal aprroach has three steps:
        // Step 1- Insert a duplicate of each node after every node
        Node* curr = head;
        while (curr != NULL) {
            Node* nxt = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nxt;
            curr = nxt;
        }

        // Step 2- assign the "random" pointer of the duplicate nodes by using the "random" pointer of original nodes.
        // the "random" of duplicate extist after the "random" of the origian node
        curr = head;
        while( curr != NULL ){
             curr->next->random = curr->random ? curr->random->next : NULL;
             curr= curr->next->next;
        }

        // Step 3 - correcting the "next" pointers of orignal and duplicate nodes.
        Node* newHead = head->next;
        curr = head;
        while (curr != NULL) {
            Node* nxt = curr->next->next;
            curr->next->next = nxt?nxt->next:NULL;
            curr->next = nxt;
            curr = nxt;
        }
        return newHead;
    }
};

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}