#include <iostream>
#include <map>

using namespace std;

void print(multimap<int, int> m) {
    for (auto x : m)
        cout << x.first << " " << x.second << endl;
    cout << endl;
}

int main() {

    multimap<int, int> m;

    // m[0] = 1 // this notation not allowed in multimap
    m.insert({0, 1});
    m.insert({2, 3});
    m.insert({4, 5});

    m.insert({2, 5}); // multiple key

    cout << m.size() << endl;

    // erase(key) will remove all occurances of 'key' in the map

    // also has access to other methods like ub, lb, equal_range, etc

    print(m);
}