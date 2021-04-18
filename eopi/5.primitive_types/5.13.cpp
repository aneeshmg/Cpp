// multiply two nos withoud using * operator - allowed operators are bitwise & assignment
#include <iostream>

using namespace std;

unsigned add_no_operator(const unsigned &a, const unsigned &b) {

    unsigned sum = 0, carryin = 0, k = 1;

    while (k) {
        unsigned ak = a & k, bk = b & k;
        unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
        sum |= ak ^ bk ^ carryin;
        carryin = carryout << 1;
        k <<= 1;
    }

    return sum;
}

unsigned multiply_no_operator(const unsigned &x, const unsigned &y) {

    unsigned sum = 0, k = 1, scaled_y = y;

    while (k) {
        // examine kth bit of x
        if (x & k) {
            sum = add_no_operator(sum, scaled_y);
        }
        k <<= 1;
        scaled_y <<= 1;
        cout << sum << " " << k << " " << scaled_y << " " << endl;
    }

    return sum;
}

int main() {

    unsigned int a = 5, b = 5;

    // needs revision, tracing

    cout << add_no_operator(a, b) << endl;
    cout << multiply_no_operator(a, b) << endl;
}