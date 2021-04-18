// gamma code, encode and decode. encoding seems trivial, but decode?
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string int_to_binary(int x) {
    string res;

    while (x) {
        res.insert(0, 1, '0' + (x & 1));
        x >>= 1;
    }

    return res;
}

string encode(const vector<int> &A) {

    string res = "";

    for (const int &a : A) {
        string bin = int_to_binary(a);
        bin.insert(0, bin.size(), '0');
        res += bin;
    }

    return res;
}

int binary_to_int(const string &bin) {
    int res = 0;

    for (const char &c : bin) {
        res = (res << 1) + c - '0';
    }

    return res;
}

vector<int> decode(const string &s) {

    vector<int> res;
    int idx = 0;

    while (idx < s.size()) {
        // count no of consecutive 0s
        int zero_count = idx;
        while (zero_count < s.size() && s[zero_count] == '0')
            zero_count++;

        int len = zero_count - idx + 1;
        res.emplace_back(binary_to_int(s.substr(zero_count, len)));
        idx = zero_count + len;
    }

    return res;
}

int main() {

    vector<int> v = {};
    // test this while revising

}