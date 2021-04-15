#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    string s1;
    string s2 = "i am";
    s1 = "batman";

    cout << s2 << " " << s1 << endl;

    string s3 = s2 + " " + s1;
    cout << s3 << endl;

    cout << s3.length() << endl;

    cout << s3.find("bat") << endl; // returns index of start of "bat"
    int x = s3.find("supes");
    if (x == string::npos) cout << "not found" << endl;

    cout << s3.substr(5, 11) << endl; // batman
}