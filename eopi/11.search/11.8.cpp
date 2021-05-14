// kth smallest in 2 sorted arrays...may have dupes
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <algorithm>

using namespace std;

template <typename T>
T find_kth_in_two_sorted(const vector<T> &A, const vector<T> &B, const int &k) {
    // lower bound of elements we will choose in A
    int l = max(0, static_cast<int>(k - A.size()));
    // upper bound of elements we will choose in B
    int u = min(static_cast<int>(A.size()), k);

    while (l < u) {
        int x = l + ((u - l) >> 1);
        T A_x_1 = (x <= 0 ? numeric_limits<T>::min() : A[x - 1]);
        T A_x = (x >= A.size() ? numeric_limits<T>::max() : A[x]);
        T B_k_x_1 = (k - x <= 0 ? numeric_limits<T>::min() : B[k - x - 1]);
        T B_k_x = (k - x >= A.size() ? numeric_limits<T>::max() : B[k - x]);

        if (A_x < B_k_x_1) {
            l = x + 1;
        } else if (A_x_1 > B_k_x) {
            u = x - 1;
        } else {
            // B[k - x - 1] <= A[x] && A[x - 1] < B[k - x]
            return max(A_x_1, B_k_x_1);
        }
    }

    T A_l_l = l <= 0 ? numeric_limits<T>::min() : A[l - 1];
    T B_k_l_1 = k - l - 1 < 0 ? numeric_limits<T>::min() : B[k - l - 1];

    return max(A_l_l, B_k_l_1);
}

int main() {

    // needs research

}