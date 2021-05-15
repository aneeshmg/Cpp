// given unsorted array, find min and max using no more than 3n/2 - 2 comparisions
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
pair<T, T> find_min_max(const vector<T> &A) {

    if (A.size() <= 1) {
        return {A.front(), A.front()};
    }

    pair<T, T> min_max_pair = minmax(A[0], A[1]);

    for (int i = 2; i + 1 < A.size(); i += 2) {
        pair<T, T> local_pair = minmax(A[i], A[i + 1]);

        min_max_pair = {min(min_max_pair.first, local_pair.first), max(min_max_pair.second, local_pair.second)};
    }

    if (A.size() & 1) {
        min_max_pair = {min(min_max_pair.first, A.back()), max(min_max_pair.second, A.back())};
    }

    return min_max_pair;
}

int main() {

    // fairly simple, clever

} 