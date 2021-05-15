// kth largest in streaming
#include <iostream>
#include <vector>
#include <istream>
#include <numeric>

using namespace std;

template <typename T>
T find_kth_largest_streaming(istringstream &sin, const int &k) {
    vector<T> M;

    T x;

    while (sin >> x) {
        M.emplace_back(x);
        if (M.size() == (k << 1) - 1) {
            // keep k largest elements and discard the rest
            nth_element(M.begin(), M.begin() + k - 1, M.end(), greater<T>());
            M.resize(k);
        }
    }

    nth_element(M.begin(), M.begin() + k - 1, M.end(), greater<T>());

    return M[k - 1];
}

int main() {

    // fairly simple, clever

} 