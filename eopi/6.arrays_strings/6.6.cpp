// Longest increasing contiguous subarray
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}

template <typename T>
pair<int, int> find_longest_increasing_subarray(const vector<T> &A) {
    int max_len = 1;
    pair<int, int> ans(0, 0);
    int i = 0;

    while (i < A.size()) {
        // check backwardly if A[j] >= A[j+1]
        bool is_skippable = false;
        for (int j = i + max_len - 1; j >= i; --j) {
            if (A[j] >= A[j + 1]) {
                i = j + 1;
                is_skippable = true;
                break;
            }
        }
        // check forwardly if is skippable
        if (is_skippable == false) {
            i += max_len - 1;
            while (i + 1 < A.size() && A[i] < A[i + 1])
                ++i, ++max_len;
        }
        ans = {i - max_len + 1, i};
    }

    return ans;
}

int main() {

    vector<int> t{3, 1, 4, 2, 5, 6, 7, 8, 1, 3};

    print(t);
    pair<int, int> ans = find_longest_increasing_subarray(t);
    cout << ans.first << " " << ans.second << endl;

    // logic understood, this test case doesn't seem to make sense...
}