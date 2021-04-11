#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    vector<int> vec { 101, 201, 130 };

    for (auto x : vec)
        cout << x;

    sort(vec.begin(), vec.end());

    for (auto x : vec) cout << x;
}