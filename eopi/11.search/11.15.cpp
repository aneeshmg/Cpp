// find missing item in a list of ip addresses, limited RAM
#include <iostream>
#include <vector>
#include <bitset>
#include <istream>

using namespace std;

int find_missing_element(ifstream &ifs) {
    vector<size_t> counter(1 << 16, 0);
    unsigned int x;

    while (ifs >> x) {
        ++counter[x >> 16];
    }

    for (int i = 0; i < counter.size(); ++i) {
        // Find one bucket that contains less than (1 << 16) elements
        if (counter[i] < (1 << 16)) {
            bitset<(1 << 16)> bit_vec;
            ifs.clear();
            ifs.seekg(0, ios:beg);

            while (ifs >> x) {
                if (i == (x >> 16)) {
                    bit_vec.set(((1 << 16) - 1) & x); //get the lower 16 bits of x
                }
            }
            ifs.close();

            for (int j = 0; j < (1 << 16); ++j) {
                if (bit_vec.test(j) == 0) {
                    return (i << 16) | j;
                }
            }
        }
    }
}

int main() {

    // fairly simple, clever

}