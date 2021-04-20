// run length encoding ie, aaaabcccdd => 4a1b3c2d
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string encoding(const string &s) {
    int count = 1;
    stringstream ss;

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1])
            count++;
        else {
            ss << count << s[i - 1];
            count = 1;
        }
    }
    ss << count << s.back();

    return ss.str();
}

string decoding(const string &s) {
    int count = 0;
    string res;

    for (const char &c : s) {
        if (isdigit(c)) {
            count = count * 10 + c - '0';
        } else {
            res.append(count , c);
            count = 0;
        }
    }

    return res;
}

int main() {

    string s = "aaaabbbccccdd";

    string encoded = encoding(s);
    string decoded = decoding(encoded);

    cout << encoded << endl;
    cout << decoded << endl;

}