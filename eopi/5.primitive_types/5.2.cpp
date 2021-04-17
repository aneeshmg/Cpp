// 64 bit num considered as an array, swap bits at given i & j and return new 64 bit number
#include <iostream>

using namespace std;

long swap_bits(long x, const int &i, const int &j) {

    if (((x >> i) & 1) != ((x >> j) & 1)) {
        x ^= (1L << i) | (1L << j);
    }

    return x;
}

int main() {

    long x = 10;

    cout << swap_bits(x, 3, 63) << endl;
}