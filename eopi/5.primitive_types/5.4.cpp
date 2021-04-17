// number of bits set in a 64bit num is its weight, Sk is set of unsigned integers whose weight is k.
// find y in Sk \ {x} such that |y - x| is min
#include <iostream>

using namespace std;

unsigned long closest_int_same_bits(unsigned long x) {
    for (int i = 0; i < 63; i++) {
        if (((x >> i) & 1) ^ ((x >> (i + 1)) & 1)) {
            x ^= (1UL << i) | (1UL << (i + 1));
            return x;
        }
    }
    throw invalid_argument("all bits are 0 or 1");
}

int main() {

    // needs research
}