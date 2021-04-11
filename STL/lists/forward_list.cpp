#include <iostream>
#include <forward_list>

using namespace std;

void print(forward_list<int> fl) {
    for (auto x : fl)
        cout << x << " ";
    cout << endl;
}

int main() {

    // forward_list => singly linked list
    // list => doubly linked list
    forward_list<int> fl = {2, 4, 6, 8};

    fl.push_front(1);
    fl.push_front(3);
    print(fl);

    // assigns new list
    fl.assign({1, 3, 5, 7, 9});
    print(fl);
    // removes one elem from list
    fl.remove(5);
    print(fl);

    // insert_after & erase_after, self explanatory, alter - emplace_after => faster for objects (as opposed to primitive data types)
    auto it = fl.insert_after(fl.begin(), 2);
    it = fl.insert_after(it, 4);
    print(fl);
    it = fl.erase_after(it);
    print(fl);

    // Other fl functions - empty() - checks if list is empty, clear()) - clears the list
    fl.reverse();
    print(fl);

    // merges one array into another and clears the argument list
    fl.merge({100, 20, 3});
    print(fl);
    // also works as merge sort, if two lists are sorted
    forward_list<int> fl1 = {1, 3, 5};
    forward_list<int> fl2 = {6, 4, 2};
    // simple sort
    fl2.sort();
    print(fl2);
    fl1.merge(fl2);
    print(fl1); // sorted & merged list
    print(fl2); // empty

}

