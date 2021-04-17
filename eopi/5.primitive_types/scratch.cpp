#include <iostream>

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
}