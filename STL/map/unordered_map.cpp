#include <iostream>
#include <unordered_map>

using namespace std;

void print(unordered_map<string, int> m) {
    for (auto x : m)
        cout << x.first << " " << x.second << endl;
    cout << endl;
}

int main() {

    // regular map uses rb tree internally whereas unordered_map uses hashing => faster
    unordered_map<string, int> m;

    m["zero"] = 1;
    m.insert({"two", 3});
    m.insert({"four", 5});

    m.insert({"two", 5}); // does not update

    cout << m.size() << endl;

    // also can use other methods like find() which returns an iterator, [] -> to get (but will initialise with default if not present), at() - same as map

    auto it = m.find("two");
    if (it != m.end()) {
        cout << (it->first) << " " << (*it).second << endl;
    }

    cout << m.count("two") << endl;

    print(m);
}