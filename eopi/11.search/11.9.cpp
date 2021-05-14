// compute square root of x
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <algorithm>

using namespace std;

int compare(const double &a, const double &b) {
    // use normalization for precision problem
    double diff = (a - b) / b;
    return diff < -numeric_limits<double>::epsilon() ? -1 : diff > numeric_limits<double>::epsilon();
}

double square_root(const double &x) {
    // decide range acc to x
    double l, r;
    if (compare(x, 1.0) < 0) {
        l = x, r = 1.0;
    } else {
        l = 1.0, r = x;
    }

    while (compare(l, r) == -1) {
        double m = l + 0.5 * (r - l);
        double square_m = m * m;
        if (compare(square_m, x) == 0) {
            return m;
        } else if (compare(square_m, x) == 1) {
            r = m;
        } else {
            l = m;
        }
    }

    return l;
}

int main() {

    // nice

}