#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}

template <typename T>
void rotate_array(vector<T> &A, int i) {
    i %= A.size();

    reverse(A.begin(), A.end());
    reverse(A.begin(), A.begin() + i);
    reverse(A.begin() + i, A.end());
}

int main() {

    vector<int> t{1, 2, 3, 4, 5};

    print(t);
    // algorithm is fairly self explanatory
    rotate_array(t, 3);
    print(t);
}