#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void print(vector<int> v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int mul(int x, int y) {
    return x * y;
}

int main() {

    // use container specific find methods for set, map, etc as this is a generic method and hence not optimized
    vector<int> v = {1, 2, 3, 4, 5, 6}; // will work for other 'vector' like types too

    // accumulate basically sums the vector from the provided range and takes in the init value as the third arg
    // can take a fourth arg which defines how the accumulation should be done
    int sum = accumulate(v.begin(), v.end(), 0);

    cout << sum << endl;

    int product = accumulate(v.begin(), v.end(), 1, mul);

    cout << product << endl;
}