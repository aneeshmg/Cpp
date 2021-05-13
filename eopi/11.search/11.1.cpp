// search for first occurance of k in a sorted array
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
int search_first_k(const vector<T> &A, const T &k) {
    int l = 0, r = A.size() - 1, res = -1;

    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (A[m] > k) {
            r = m - 1;
        } else if (A[m] == k) {
            // we found k, but there can be dup k on its left
            res = m, r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return res;
}

int main() {

    // simple enough

}