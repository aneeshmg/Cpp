// kth largest in unsorted, O(n) - order statistics
#include <iostream>
#include <vector>
#include <numeric>
#include <random>

using namespace std;

template <typename T>
int partition(vector<T> &A, const int &l, const int &r, const int &pivot) {
    T pivot_value = A[pivot];
    int larger_index = l;

    swap(A[pivot], A[r]);
    for (int i = l; i < r; ++i) {
        if (A[i] > pivot_value) {
            swap(A[i], A[larger_index++]);
        }
    }

    swap(A[r], A[larger_index]);

    return larger_index;
}

template <typename T>
T find_kth_largest(vector<T> A, const int &k) {
    int l = 0, r = A.size() - 1;

    while (l <= r) {
        default_random_engine gen((random_device())());
        uniform_int_distribution<int> dis(l, r);
        int p = partition(A, l, r, dis(gen));

        if (p = k - 1) {
            return A[p];
        } else if (p > k - 1) {
            r = p - 1;
        } else {
            l = p + 1;
        }
    }
}

int main() {

    // understand how the partitioning works

} 