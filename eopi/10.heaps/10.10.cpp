// algorithm to determine if kth largest in max_heap is <,  == or > than given x
// needs to handle dupes, no more than O(k) space and time to be independent of number of elements in heap, immutable heap
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void compare_kth_largest_helper(const vector<T> &max_heap, const int &k, const T &x, const int &idx, int &larger, int &equal) {
    if (idx < max_heap.size()) {
        if (max_heap[idx] < x) {
            return;
        } else if (max_heap[idx] == x) {
            ++equal;
        } else {
            ++larger;
        }
    }

    if (equal < k && larger < k) {
        compare_kth_largest_helper(max_heap, k, x, (idx << 1) + 1, larger, equal);
        compare_kth_largest_helper(max_heap, k, x, (idx << 1) + 2, larger, equal);
    }
}

template <typename T>
int compare_kth_largest(const vector<T> &max_heap, const int &k, const T &x) {
    int larger = 0, equal = 0;

    compare_kth_largest_helper(max_heap, k, x, 0, larger, equal);

    return larger >= k ? 1 : (larger + equal >= k ? 0 : -1);
}

int main() {

    //
}