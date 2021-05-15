#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>

using namespace std;

void print(const vector<int> &t) {
    for (auto x : t)
        cout << x << ' ';
    cout << endl;
}

int main() {

    vector<int> t = {1, 2, 3, 4, 5, 6, 7,8 };
    vector<int> prefix_sum;

    partial_sum(t.begin(), t.end(), back_inserter(prefix_sum));

    print(t);
    print(prefix_sum);

    cout << minmax(4, 2).first << endl;

    default_random_engine gen((random_device())());
    uniform_int_distribution<int> dis(t[0], t[t.size() - 1]);

    cout << dis(gen) << endl;
}