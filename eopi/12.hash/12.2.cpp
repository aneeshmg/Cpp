// build hash function for chess state...
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

    // an extention of 12.1...complex...know how it is done..no code provided
}