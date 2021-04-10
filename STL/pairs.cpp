#include <iostream>
#include <utility>

using namespace std;

int main() {
    cout << "Pairs:" << endl;

    pair<int, int> p(1, 2), p2;

    cout << p.first << " " << p.second << endl;

    p2 = make_pair(10, 20);

    cout << p2.first << " " << p2.second << endl;
}