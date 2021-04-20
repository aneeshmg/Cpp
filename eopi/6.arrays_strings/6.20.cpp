// string search
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int base = 26, mod = 997;

int rabin_karp(const string &t, const string &s) {
    // t is text, s is substring/pattern
    if (s.size() > t.size()) {
        return -1;
    }

    int t_hash = 0, s_hash = 0;

    for (int i = 0; i < s.size(); ++i) {
        t_hash = (t_hash * base + t[i]) % mod;
        s_hash = (s_hash * base + s[i]) % mod;
    }

    for (int i = s.size(); i < t.size(); ++i) {
        // in case of hash collision, check if the two substrings are actually equal
        if (t_hash == s_hash && t.compare(i - s.size(), s.size(), s) == 0)
            return i - s.size(); //find match

        t_hash -= (t[i - s.size()] * static_cast<int>(pow(base, s.size() - 1))) % mod;

        if (t_hash < 0)
            t_hash += mod;

        t_hash = (t_hash * base + t[i]) % mod;
    }

    if (t_hash == s_hash && t.compare(t.size() - s.size(), s.size(), s) == 0) {
        return t.size() - s.size();
    }

    return -1;
}

int main() {

    // needs code walkthrough in rev
    string t = "abcdxyzalmnop", s = "xyza", p = "xyzk";

    cout << rabin_karp(t, s) << endl;
    cout << rabin_karp(t, p) << endl;

}