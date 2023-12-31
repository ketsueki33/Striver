#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379

struct Node {
    int val, vNo, ind;

    Node(int a, int b, int c) {
        val = a;
        vNo = b;
        ind = c;
    }
};

struct myCmp {
    bool operator()(Node const &v1, Node const &v2) {
        return v1.val > v2.val;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k) {
    // we define a custom struct to hold the smallest element in each vector, the vector number, and the index of that element.
    // we push a node for each vector.
    // then till the pq is empty, take the top node ( it is the smallest value overall ) and push it to result.
    // if afer removing the current val from the vector, it is not empty
    //          -change the val in node to the next element
    //          -change the ind in node to the index of next element
    //          -push node to pq
    priority_queue<Node, vector<Node>, myCmp> pq;

    for (int i = 0; i < k; i++) {
        Node temp(kArrays[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> res;

    while (!pq.empty()) {
        Node temp = pq.top();
        pq.pop();
        res.push_back(temp.val);
        if (temp.ind < kArrays[temp.vNo].size() - 1) {
            temp.ind++;
            temp.val = kArrays[temp.vNo][temp.ind];
            pq.push(temp);
        }
    }

    return res;
}

int main() {
    turbo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}