// kth largest in streaming data
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
void find_kth_largest(istringstream &sin, const int &k) {
    priority_queue<T, vector<T>, greater<T>> min_heap;

    T x;

    for (int i = 0; i < k && sin >> x; ++i) {
        min_heap.emplace(x);
        cout << min_heap.top() << endl;
    }

    while (sin >> x) {
        if (min_heap.top() < x) {
            min_heap.pop();
            min_heap.emplace(x);
        }
        cout << min_heap.top() << endl;
    }
}

int main() {

    // use min-heap
    // how to test?
}