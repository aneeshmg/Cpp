#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}

int main() {

    vector<int> t(5);

    // basically to fill in array increments of 1
    iota(t.begin(), t.end(), 5);
    print(t); // 5, 6, 7, 8, 9
}