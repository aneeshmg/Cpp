#include <iostream>
#include <map>

using namespace std;

void print(map<int, int> m) {
    for (auto x : m)
        cout << x.first << " " << x.second << endl;
    cout << endl;
}

int main() {

    map<int, int> m;

    m[0] = 1;
    m.insert({2, 3});
    m.insert({4, 5});

    m.insert({2, 5}); // makes no difference (behaves like set)

    cout << m.size() << endl;

    // since m[6] does not exist, it gets created and a default value gets entered as its value
    // square notation is good to update already existing values
    cout << m[6] << endl;

    // below line will throw out of range exception, since the key 8 does not exist, hence safer. if key exists, it updates the value
    //m.at(8) = 9;

    // also has access to other methods like begin(), end(), etc

    // find() works the same...returns an iterator NOT the value
    // erase() takes in key as argument and removes that key-value from the map

    // map is internally implemented as a rb tree just like set, so anything that applies to set also applies to map

    print(m);
}