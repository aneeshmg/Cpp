// approximate sort
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
void approximate_sort(istringstream &sin, const int &k) {
    priority_queue<T, vector<T>, greater<T>> min_heap;

    // first push k elements into heap
    T x;
    for (int i = 0; i < k && sin >> x; ++i) {
        min_heap.push(x);
    }

    // now extract min for every new incoming element
    while (sin >> x) {
        min_heap.push(x);
        cout << min_heap.top() << endl;
        min_heap.pop();
    }

    // when stream stops, pop out the remaining from the heap
    while (!min_heap.empty()) {
        cout << min_heap.top() << endl;
        min_heap.pop();
    }
}

int main() {

    //
}