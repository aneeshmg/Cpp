#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <typename T>
void generate_power_set_helper(const vector<T> &S, int idx, vector<T> &res) {

    // res will be the subset
    if (res.empty() == false) {
        // print the subset
        copy(res.cbegin(), res.cend() - 1, ostream_iterator<T>(cout, ", "));
        cout << res.back();
    }
    cout << endl;

    for (int i = idx; i < S.size(); ++i) {
        res.emplace_back(S[i]);
        generate_power_set_helper(S, i + 1, res);
        res.pop_back();
    }
}

template <typename T>
void generate_power_set(const vector<T> &S) {

    vector<T> res;
    generate_power_set_helper(S, 0, res);
}

int main() {

    // compute power set
    vector<int> s = {1, 2, 3};

    generate_power_set(s);
}