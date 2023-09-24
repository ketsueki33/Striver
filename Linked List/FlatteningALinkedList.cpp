#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// https://www.youtube.com/watch?v=ysytSSXpAI0 - approach 2

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

struct myCmp {
    bool operator()(const Node *n1, const Node *n2) {
        return n1->data > n2->data;
    }
};
// approach 1 - we use a min heap to store the head of all the linked lists
// we select the min node and add it to the list. We also add the bottom of that min node to the min heap.
// this is repeated till the min heap is empty
// this approach uses O(k) extra space where k is the no. of linked lists.
Node *flatten(Node *root) {
    priority_queue<Node *, vector<Node *>, myCmp> pq;
    while (root != NULL) {
        pq.push(root);
        root = root->next;
    }
    Node *dummy = new Node(-1);
    Node *prev = dummy;

    while (!pq.empty()) {
        Node *curr = pq.top();
        pq.pop();
        if (curr->bottom != NULL) {
            pq.push(curr->bottom);
        }
        prev->bottom = curr;
        curr->next = NULL;
        prev = curr;
    }

    return dummy->bottom;
}

Node *mergeTwoLists(Node *a, Node *b) {
    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        } else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;

    return res->bottom;
}

// approach 2 - here we merge the last two linked lists recursively till we end up with a single flattened
// linked list.
// this approach uses no extra space.
Node *flatten2(Node *root) {
    if (root == NULL || root->next == NULL)
        return root;

    // recur for list on right
    root->next = flatten2(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    // return the root
    // it will be in turn merged with its left
    return root;
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}