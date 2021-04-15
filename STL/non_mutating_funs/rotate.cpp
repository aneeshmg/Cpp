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
    vector<int> v = {1, 2, 3, 4, 5, 6}; // will work for other 'vector' like types too

    print(v);

    // rotates the vector about the middle argument
    // basically, v.begin() + kth element becomes the first element
    rotate(v.begin(), v.begin() + 3, v.end());

    print(v);

    // linear complexity...can be used on any container that provides a forward iterator
}