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
    vector<int> v1 = {1, 2, 3, 4, 5, 6}; // will work for other 'vector' like types too
    vector<int> v2 = {2, 6, 1, 4, 3, 5};

    if (is_permutation(v1.begin(), v1.end(), v2.begin())) // can also consider specific ranges by manipulating begin, end iterators 
        cout << "v2 is a permutation of v1" << endl;

    // can use for set, map, etc...wrt keys
    // worse case this is O(n^2) hence use only for simple cases
}