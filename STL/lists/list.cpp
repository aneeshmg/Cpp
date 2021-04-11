#include <iostream>
#include <list>

using namespace std;

void print(list<int> fl) {
    for (auto x : fl)
        cout << x << " ";
    cout << endl;
}

int main() {

    // a list is a dl list
    list<int> l = {3, 5, 7};

    l.push_front(1);
    l.push_back(9);
    print(l);
    // similarly pop_front, pop_back - self explanatory

    // other self explanatory functions - insert(), front(), back(), size(), erase(), remove(), merge(), reverse(), sort()

    // unique() - removes consecutive duplicates
    l = {1, 1, 2, 2, 3, 3, 4, 4};
    l.unique();
    print(l);
}