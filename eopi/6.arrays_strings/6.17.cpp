// matrix rotation
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>> &t) {
    for (auto x : t) {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

void rotate_matrix(vector<vector<int>> &A) {

    // logic is fairly simple...first transpose the matrix and then reverse the columns => O(1) space
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i; j < A.size(); ++j) {
            swap(A[i][j], A[j][i]);
        }
    }

    // print(A);

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0, k = A.size() - 1; j < k; ++j, --k) {
            swap(A[j][i], A[k][i]);
        }
    }
}

int main() {

    vector<vector<int>> t = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    print(t);
    cout << "------" << endl;

    rotate_matrix(t);

    print(t);

}