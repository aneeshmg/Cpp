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

    next_permutation(v.begin(), v.end());
    print(v); // 1 2 3 4 6 5

    v = {6, 5, 4, 3, 2, 1};
    next_permutation(v.begin(), v.end());
    print(v); // 1 2 3 4 5 6


}