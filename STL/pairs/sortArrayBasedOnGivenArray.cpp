#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

vector<int> customSort(vector<int> a, vector<char> b, int n) {

    pair<char, int> p[n];
    vector<int> c;

    for (int i = 0; i < n; i++)
        p[i] = {b[i], a[i]};
    for (auto x : p) cout << "(" << x.first << ", " << x.second << "), ";

    sort(p, p + n);

    for (int i = 0; i < n; i++)
        c.push_back(p[i].second);
    cout << endl;

    return c;
}

int main() {

    vector<int> a { 3, 2, 1 };
    vector<char> b { 'c', 'a', 'b' };

    vector<int> c = customSort(a, b, 3);

    for (auto x : c) cout << x << ", ";

    return 0;
}