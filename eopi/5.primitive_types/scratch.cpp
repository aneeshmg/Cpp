#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {

    int i = 2;

    cout << (i << 1) << endl;
    cout << (i << 2) << endl;

    cout << (i ^ 0) << endl;

    cout << (i & 10) << endl;

    cout << i << endl;
    cout << (i & (i - 1)) << endl;

    cout << 1L << endl;

    vector<int> t = {1, 2, 3, 4, 5};

    copy(t.cbegin(), t.cend() - 1, ostream_iterator<int>(cout, ", ")); // this will only print till N-1 items
    cout << t.back() << endl; // hence this, as used in 5.5

    unsigned int k = 1;
    while (k) {
        k <<= 1;
        cout << k << " "; // assumed this would result in infinite loop but it terminates at the 32nd iteration (hits 0)
    }
    cout << endl;
}