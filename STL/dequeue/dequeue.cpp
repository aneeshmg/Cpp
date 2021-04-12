#include <iostream>
#include <deque>

using namespace std;

void print(deque<int> fl) {
    for (auto x : fl)
        cout << x << " ";
    cout << endl;
}

int main() {

    // basically stack/queue
    deque<int> d = {1, 3, 5};

    d.push_back(2);
    d.push_front(4);

    // other available methods - insert(), size(), pop_front(), pop_back(), [c|r][begin|end]() & others like begin(), end(), front(), back(), etc
    // implemented internally using circular array, unlike in other languages which use dl-list, but this offers random access as well

    print(d);
}