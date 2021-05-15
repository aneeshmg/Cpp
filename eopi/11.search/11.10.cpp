// search in 2D array
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool matrix_search(const vector<vector<T>> &A, const T &x) {
    int r = 0, c = A[0].size() - 1;

    while (r < A[0].size() && c >= 0) {
        if (A[r][c] == x) {
            return true;
        } else if (A[r][c] < x) {
            ++r;
        } else {
            ++c;
        }
    }

    return false;
}

int main() {

    // fairly simple, clever

} 