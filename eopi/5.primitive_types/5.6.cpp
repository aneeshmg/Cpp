#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string integer_to_string(int x) {
    bool is_negative;

    if (x < 0) {
        is_negative = true;
        x = -x;
    } else is_negative = false;

    string s;

    while (x) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    if (s.empty())
        return {"0"};

    if (is_negative)
        s.push_back('-');

    reverse(s.begin(), s.end());

    return s;
}

int string_to_integer(string s) {
    bool is_negative = s[0] == '-';

    int x = 0;

    for (int i = is_negative; i < s.size(); i++) {
        if (isdigit(s[i])) {
            x = x * 10 + s[i] - '0';
        } else throw invalid_argument("illegal input");
    }

    return is_negative ? -x : x;
}

int main() {

    // convert string to integer and integer to string
    string s1 = "120";
    string s2 = "-210";
    int i1 = 230;
    int i2 = 150;

    cout << integer_to_string(i1) << " " << integer_to_string(i2) << endl;
    cout << string_to_integer(s1) << " " << string_to_integer(s2) << endl;
}