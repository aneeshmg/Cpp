// given directory paths, return shortest path
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

string normalise_path(const string &path) {
    vector<string> s;

    if (path.front() == '/')
        s.emplace_back("/");

    stringstream ss(path);
    string token;

    while (getline(ss, token, '/')) {
        if (token == "..") {
            if (s.empty() || s.back() == "..")
                s.emplace_back(token);
            else {
                if (s.back() == "/")
                    throw invalid_argument("path error");
                s.pop_back();
            }
        } else if (token != "."  && token != "") {
            for (const char &c : token) {
                if (c != '.' && isalnum(c) == false)
                    throw invalid_argument("invalid dir name");
            }
            s.emplace_back(token);
        }
    }

    string normalized_path("");
    if (s.empty() == false) {
        auto it = s.cbegin();
        normalized_path += *it++;
        while (it != s.cend()) {
            if (*(it - 1) != "/")
                normalized_path += "/";
            normalized_path += *it++;
        }
    }

    return normalized_path;
}

int main() {

    // fairly straightforward > nothing strange, need to learn manipulation of string streams, splittin ,etc
    // test in rev
}