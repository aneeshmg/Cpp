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

    fill(v.begin() + 2, v.end() - 2, 0); // will fill the vector with whatever was sent in

    print(v);

    // works on strings too
    // linear complexity
}