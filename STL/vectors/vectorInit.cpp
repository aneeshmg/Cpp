#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (auto i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    // .at() does an index out of bound check before seg fault
    for (auto i = 0; i < v.size(); i++)
        cout << v.at(i) << endl;

    for (auto x : v)
        cout << x << endl;

    // to prevent changes to elements of array
    for (const int i : v)
        cout << i << endl;

    // each of v typically gets copied over to i, so using & will copy by reference, allowing modification (unless const is used) and is faster
    for (int &i : v)
        cout << i << endl;

    // using iterators
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << endl;

    // traverses in reverse, ++ goes in reverse here
    for (auto it = v.rbegin(); it != v.rend(); it++)
        cout << (*it) << endl;

    // Similarly, cbegin & cend => cannot change values of vector and rcbegin & rcend => same as cbegin and cend but in reverse

    // More vector util functions:
    // these two are references => values are updatable
    cout << v.front() << " " << v.back() << endl;
    v.insert(v.begin(), 10);
    cout << v.front() << endl;

    // shortens from the right if size is more than the passed in num & inserts default value if extended
    v.resize(5);

    // remove an element at i - needs to be reference
    v.erase(v.end() - 1);
    for (auto x : v)
        cout << x << endl;

    // empty returns a bool, clear does the expected
    if (!v.empty())
        v.clear();
}