#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// https://www.codingninjas.com/studio/problems/count-inversions_615
// https://www.youtube.com/watch?v=AseUmwVNaoY

#define ll long long

ll countMerge(ll *arr, ll l, ll m, ll r) {
    ll n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    ll left[n1], right[n2];
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

    ll res = 0, i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
            k++;
        } else {
            // if this conditions is reached , it means the elements were in inversion and all the elements
            // in the 'left' array after 'i' are in inversion.
            arr[k] = right[j];
            res = res + (n1 - i);
            j++;
            k++;
        }
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

ll mergeSort(ll *arr, ll l, ll r) {
    // we initialise res to keep count of the inversions
    ll res = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        res += mergeSort(arr, l, m);
        res += mergeSort(arr, m + 1, r);
        res += countMerge(arr, l, m, r);
    }
    return res;
}

long long getInversions(long long *arr, int n) {
    // we use merge sort to count the inversions in an array
    return mergeSort(arr, 0, n - 1);
}

int main() {
    turbo;
    ll arr[] = {36343342, 658445766, 281323766, 703538013, 437455363, 900766801, 84401391, 159903601, 626186515, 127519304, 222484765, 609828661, 190927389, 152625748, 358752776, 522920848, 494568773, 977351598, 782415711, 966011559};
    cout << getInversions(arr, 20);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

    return 0;
}