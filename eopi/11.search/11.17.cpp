// find an element that occurs just once, others appear 3ce
#include <iostream>
#include <vector>

using namespace std;

int find_element_appears_once(const vector<int> &A) {
    int ones = 0, twos = 0;
    int next_ones = 0, next_twos = 0;

    for (const int &i : A) {
        next_ones = (~i & ones) | (i & ~ones & ~twos);
        next_twos = (~i & twos) | (i & ones);
        ones = next_ones, twos = next_twos;
    }

    return ones;
}

int main() {

    // fairly simple, clever

} 