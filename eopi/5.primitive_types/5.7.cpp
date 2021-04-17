#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convert_base(const string &s, const int &b1, const int &b2) {

    bool neg = s.front() == '-';
    int x = 0;

    for (int i = (neg == true ? 1 : 0); i < s.size(); i++) {
        x *= b1;
        x += isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
    }

    string ans;
    while (x) {
        int r = x % b2;
        ans.push_back(r >= 10 ? 'A' + r - 10: '0' + r);
        x /= b2;
    }

    if (ans.empty())
        ans.push_back('0');

    if (neg)
        ans.push_back('-');

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    // base conversion
    int b1 = 2, b2 = 10;
    string s = "1010";

    cout << convert_base(s, b1, b2) << endl;
}