// search in sorted-rotated array of unknown length
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int binary_search_unknown_length(const vector<T> &A, const T &k) {
    // find the possible range where k exists
    int p = 0;

    while (true) {
        try {
            T val = A.at((1 << p) - 1);
            if (val == k) {
                return (1 << p) - 1;
            } else if (val > k) {
                break;
            }
        } catch (exception &e) {
            break;
        }
        ++p;
    }

    // binary search between 2^(p - 1) + 1 to 2^p - 2
    int l = (1 << (p - 1)) + 1, r = (1 << p) - 2;

    while (l <= r) {
        int m = l + ((r - l) >> 1);

        try {
            T val = A.at(m);
            if (val == k) {
                return m;
            } else if (val > k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } catch (exception &e) {
            r = m - 1;
        }
    }

    return -1;
}

int main() {

    // relatively complex, but understandable

}