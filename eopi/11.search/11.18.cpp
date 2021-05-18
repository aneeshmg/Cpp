// searching an array with close entries
#include <iostream>
#include <vector>

using namespace std;

int close_search(const vector<int> &A, const int &k) {
    int idx = 0;

    while (idx < A.size() && A[idx] != k) {
        idx += abs(A[idx] - k);
    }

    return idx < A.size() ? idx : -1;
}

int main() {

    // fairly simple, clever...skip and search..linear search-ish

}