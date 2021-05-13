// search in sorted-rotated array for smallest
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int search_smallest(const vector<T> &A) {
    int l = 0, r = A.size() - 1;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (A[m] > A[r])
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main() {

    // fairly simple, clever

} 