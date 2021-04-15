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

    auto it = find(v.begin(), v.end(), 3); // you can also search in a range like 'v.begin() + k', 'v.end() - l'
    if (it != v.end()) cout << (*it) << endl;
}