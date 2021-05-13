// search a sorted array for A[i] = i
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int search_index_value_equal(const vector<T> &A) {
    int l = 0, r = A.size() - 1;

    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int val = A[m] - m;
        if (val == 0) return m;
        else if (val > 0) r = m - 1;
        else l = m + 1;
    }

    return -1;
}

int main() {

    // simple enough

}