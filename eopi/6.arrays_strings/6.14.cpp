// sudoku checker (not solver)
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}

bool is_valid_sudoku(const vector<vector<int>> &A) {
    // check row constraints
    for (int i = 0; i < A.size(); ++i) {
        vector<bool> is_present(A.size() + 1, false);
        for (int j = 0; i < A.size(); ++j) {
            if (A[i][j] != 0 && is_present[A[i][j]] == true)
                return false;
            else
                is_present[A[i][j]] = true;
        }
    }

    // check column constraints
    for (int j = 0; j < A.size(); ++j) {
        vector<bool> is_present(A.size() + 1, false);
        for (int i = 0; i < A.size(); ++j) {
            if (A[i][j] != 0 && is_present[A[i][j]] == true)
                return false;
            else
                is_present[A[i][j]] = true;
        }
    }

    // check region constraints
    int region_size = sqrt(A.size());
    for (int I = 0; I < region_size; ++I) {
        for (int J = 0; J < region_size; ++J) {
            vector<bool> is_present(A.size() + 1, false);
            for (int i = 0; i < region_size; ++i) {
                for (int j = 0; j < region_size; ++j) {
                    if (A[region_size * I + i][region_size * J + j] != 0 && is_present[A[region_size * I + i][region_size * J + j]] == true)
                        return false;
                    else
                        is_present[A[region_size * I + i][region_size * J + j]] = true;
                }
            }
        }
    }

    return true;
}

int main() {

    vector<vector<int>> t;

    // test in rev
}