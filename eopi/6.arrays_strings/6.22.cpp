// phone number pneumonic
#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

const array<string, 10> M = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void pneumonic_helper(const string &num, const int &d, string &ans) {
    if (d == num.size()) {
        cout << ans << endl;
    } else {
        for (const char &c : M[num[d] - '0']) {
            ans[d] = c;
            pneumonic_helper(num, d + 1, ans);
        }
    }
}

void pneumonic(const string &num) {
    string ans(num.size(), 0);

    pneumonic_helper(num, 0, ans);
}

int main() {

    pneumonic("23");
}