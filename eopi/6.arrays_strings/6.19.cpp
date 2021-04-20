// reverse all words in a sentence
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverse_words(string &s) {

    // logic here is to first reverse the entire string and then reverse each word in string
    reverse(s.begin(), s.end());

    size_t start = 0, end;

    while ((end = s.find(" ", start)) != string::npos) {
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
    }

    // reverse the last word
    reverse(s.begin() + start, s.end());
}

int main() {

    string s = "Alice and Bob are friends";

    cout << s << endl;
    reverse_words(s);
    cout << s << endl;
}