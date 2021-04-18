// convert spreadsheet column, beyond 26 to integer from the alphabet, like AA, AB, AC, etc
#include <iostream>
#include <string>

using namespace std;

int ssDecodeColId(const string &col) {
    int res = 0;

    for (const char &c : col)
        res = res * 26 + c - 'A' + 1;

    return res;
}

int main() {

    // main idea is base conversion, of base 26
    string s = "AAA";

    cout << ssDecodeColId(s) << endl;
}