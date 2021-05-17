// find duplicate and missing elements
#include <iostream>
#include <vector>

using namespace std;

// return pair<duplicate, missing>
pair<int, int> find_duplicate_missing(const vector<int> &A) {
    int miss_xor_dup = 0;

    for (int i = 0; i < A.size(); ++i) {
        miss_xor_dup ^= A[i];
    }

    int differ_bit = miss_xor_dup & (~(miss_xor_dup - 1)), miss_or_dup = 0;

    for (int i = 0; i < A.size(); ++i) {
        if (i & differ_bit)
            miss_or_dup ^= i;
        if (A[i] & differ_bit)
            miss_or_dup ^= A[i];
    }

    for (const int &A_i : A) {
        if (A_i == miss_or_dup) {
            return {miss_or_dup, miss_or_dup ^ miss_xor_dup};
        }
    }
    // miss_or_dup is missing element
    return {miss_or_dup ^ miss_xor_dup, miss_or_dup};
}

int main() {

    // needs understanding..kinda confusing

} 