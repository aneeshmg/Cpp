// replace and remove
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string replace_and_remove(string s) {
    // remove b and count number of a
    int write_idx = 0, a_count = 0;

    for (const char &c : s) {
        if (c != 'b')
            s[write_idx++] = c;

        if (c == 'a')
            a_count++;
    }

    // allocate space based on a_count
    s.resize(write_idx + a_count);
    // now replace a with dd
    int curr_idx = write_idx - 1;
    write_idx = s.size() - 1;

    while (curr_idx >= 0) {
        if (s[curr_idx] == 'a') {
            s[write_idx--] = s[write_idx] = 'd';
        } else {
            s[write_idx--] = s[curr_idx];
        }
        --curr_idx;
    }

    return s;
}

int main() {

    string s = "abbcdweddffabdkckd";

    // test in rev
}