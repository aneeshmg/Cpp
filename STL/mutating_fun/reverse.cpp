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

    // requires bi-directional iterators => forward_list is not applicable here
    reverse(v.begin(), v.end());
    print(v);
}