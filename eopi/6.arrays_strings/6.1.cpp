// dutch flag problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T>
void dutch_flag(vector<T> &A, const int &pivot_index) {

    T pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = A.size() - 1;

    // when there are unclassified items
    while (equal <= larger) {
        if (A[equal] < pivot) {
            swap(A[smaller++], A[equal++]);
        } else if (A[equal] == pivot) {
            equal++;
        } else {
            swap(A[equal], A[larger--]);
        }
        print(A);
    }
}

int main() {

    vector<int> t = {5, 3, 4, 8, 10, 1, 7, 2, 9, 6};

    // fairly straightforward...pointer manipulation

    dutch_flag(t, 6);
}