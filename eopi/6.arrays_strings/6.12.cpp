// next permutation
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}

vector<int> next_permutation(vector<int> p) {
    int k = p.size() - 1;

    while (k > 0 && p[k] >= p[k + 1]) {
        k--;
    }

    if (k == -1) {
        return {}; //already on the last permutation
    }

    int l;
    for (int i = k + 1; i < p.size(); ++i) {
        if (p[i] > p[k])
            l = i;
        else
            break;
    }
    swap(p[k], p[l]);
    reverse(p.begin() + k + 1, p.end());

    return p;
}

int main() {
    vector<int> t = {1, 2, 3, 4, 5};

    print(t);

    t = next_permutation(t);

    print(t);
}