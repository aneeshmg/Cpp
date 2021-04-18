// enumerate primes from 1 to N
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> primes(const int &n) {
    int size = floor(0.5 * (n - 3)) + 1;

    // is_prime[i] represents (2i + 3) is prime or not
    vector<int> primes;
    primes.emplace_back(2);
    vector<bool> is_prime(size, true);

    for (long i = 0; i < size; i++) {
        if (is_prime[i]) {
            int p = (i << 1) + 3;
            primes.emplace_back(p);

            // this is the seive - read up during rev
            for (long j = ((i * i) << 1) + 6 * i + 3; j < size; j += p) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

int main() {

    vector<int> ps = primes(15);

    for(auto i : ps) cout << i << " ";
    cout << endl;
}