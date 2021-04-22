// given a list, arrange elements in odd-even manner, with O(1) space
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class node_t {
    public:
        T data;
        shared_ptr<node_t<T>> next;
};

template <typename T>
shared_ptr<node_t<T>> make_node(T data) {
    shared_ptr<node_t<T>> temp(new node_t<T>());
    temp->data = data;
    temp->next = NULL;
    return temp;
}

template <typename T>
void print(shared_ptr<node_t<T>> head) {

    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

template <typename T>
void append_node(shared_ptr<node_t<T>> &head, shared_ptr<node_t<T>> &tail, shared_ptr<node_t<T>> &n) {
    head ? tail->next = n : head = n;
    tail = n;
}

template <typename T>
shared_ptr<node_t<T>> odd_even(const shared_ptr<node_t<T>> &L) {

    shared_ptr<node_t<T>> odd = L ? L->next : nullptr;
    shared_ptr<node_t<T>> odd_curr = odd;
    shared_ptr<node_t<T>> pre_even_curr = nullptr, even_curr = L;

    while (even_curr && odd_curr) {
        even_curr->next = odd_curr->next;
        pre_even_curr = even_curr;
        even_curr = even_curr->next;

        if (even_curr) {
            odd_curr->next = even_curr->next;
            odd_curr = odd_curr->next;
        }
    }

    // odd number of nodes
    if (even_curr) {
        pre_even_curr = even_curr;
    }

    // prevent empty list
    if (pre_even_curr) {
        pre_even_curr->next = odd;
    }

    return L;
}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 10; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    // no clue how this works...trace it out in rev

    print(f);

    f = odd_even(f);

    print(f);



}