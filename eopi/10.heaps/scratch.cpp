#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &t) {
    for (auto x : t)
        cout << x << ' ';
    cout << endl;
}

int main() {

    vector<int> t = {1, 2, 3};

    print(t);
    // t.emplace(11); // error
    t.emplace_back(20);

    print(t);
}