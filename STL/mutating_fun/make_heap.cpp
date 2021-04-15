#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main() {

    // use container specific find methods for set, map, etc as this is a generic method and hence not optimized
    vector<int> v = {4, 6, 1, 3, 5, 2}; // will work for other 'vector' like types too

    print(v);

    // make heap creates a heap for you, max heap by default
    make_heap(v.begin(), v.end());
    cout << v.front() << endl;

    v = {4, 6, 1, 3, 5, 2};

    make_heap(v.begin(), v.end(), greater<int>());
    cout << v.front() << endl;

    pop_heap(v.begin(), v.end(), greater<int>());
    cout << v.front() << endl;

    print(v);
    v[5] = -1;

    push_heap(v.begin(), v.end(), greater<int>());
    cout << v.front() << endl;
}