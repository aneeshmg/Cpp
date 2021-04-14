#include <iostream>
#include <set>

using namespace std;

void print(multiset<int> s) {
    for (auto x : s)
        cout << x<< " ";
    cout << endl;
}

int main() {

    // allows for multiple instances of elements

    // internally uses red-black tree
    multiset<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(4);
    s.insert(1);
    s.insert(7);

    print(s);

    cout << s.count(1) << endl;

    if (s.find(2) != s.end())
        cout << "2 found" << endl;
    else
        cout << "2 not found" << endl;

    if (s.count(1) == 1)
        cout << "1 found" << endl;

    // lower bound - returns iterator to element greater than or equal to argument
    auto it = s.lower_bound(2);
    if (it != s.end()) cout << (*it) << endl;

    // upper bound - returns the first element lesser than the argument, if present
    it = s.upper_bound(3);
    if (it != s.end()) cout << (*it) << endl;

    multiset<int> s2;

    for (int i = 1; i <= 20; i += 2) s2.insert(i);

    // this stuff is still a bit strange...
    print(s2);
    it = s2.upper_bound(18);
    cout << (*it) << endl;
    it = s2.lower_bound(15);
    cout << (*it) << endl;

    // somethings not working here...first gives lb, second gives ub
    auto multi_it = s2.equal_range(9);
    cout << (*multi_it).first << "  " << (*multi_it).second << endl;
}