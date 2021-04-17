// computing parity of a very large number

#include <iostream>

using namespace std;

short parity(unsigned long x) {
    short res = 0;

    while (x) {
        res ^= (x & 1);
        x >>= 1;
    }

    return res;
}

short parity2(unsigned long x) {
    short res = 0;

    while (x) {
        res ^= 1;
        x &= (x - 1);
    }

    return res;
}

// most optimum way is to pre compute parity table for every 16 bit num and xor them 16 bit at a time to return result

int main() {

    unsigned long x = 11;

    cout << parity(x) << endl;
    cout << parity2(x) << endl;
}