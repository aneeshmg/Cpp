#include <iostream>
#include <unordered_set>

using namespace std;

void print(unordered_set<int> s) {
    for (auto x : s)
        cout << x<< " ";
    cout << endl;
}

int main() {

    // does not maintain any order of the elements
    // has access to other vector methods like empty(), begin(), end(), rend(), find(), clear(), erase()

    // internally uses hashing
    unordered_set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(4);
    s.insert(1);
    s.insert(7);

    cout << s.size() << endl;

    print(s);

    if (s.find(2) != s.end())
        cout << "2 found" << endl;
    else
        cout << "2 not found" << endl;

    if (s.count(1) == 1)
        cout << "1 found" << endl;

}