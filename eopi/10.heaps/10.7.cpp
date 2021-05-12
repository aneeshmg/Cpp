// k items closest to median, given the array
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
double find_median(vector<T> &A) {
    int half = A.size() >> 1;

    nth_element(A.begin(), A.begin() + half, A.end());
    if (A.size() & 1) {
        return A[half];
    } else {
        T x = A[half];
        nth_element(A.begin(), A.begin() + half - 1, A.end());
        return 0.5 * (x + A[half - 1]);
    }
}

template <typename T>
class Comp {
    private:
        double m_;

    public:
        Comp(const double &m) : m_(m) {};

        const bool operator()(const T &a, const T &b) const {
            return fabs(a - m_) < fabs(b - m_);
        }
};

template <typename T>
vector<T> find_k_closest_to_median(vector<T> A, const int &k) {
    nth_element(A.begin(), A.begin() + k - 1, A.end(), Comp<T>{find_median(A)});
    return {A.begin(), A.begin() + k};
}

int main() {

    // no idea how this works...find out more
}