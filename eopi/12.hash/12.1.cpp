// build hash function for string
#include <iostream>

using namespace std;

int string_hash(const string &str, const int &modulus) {
    const int MULT = 997;
    int val = 0;

    for (const char &c : str) {
        val = (val * MULT + c) % modulus;
    }

    return val;
}

int main() {

    // notice the rolling hash...magic numbers? is it prime?
}