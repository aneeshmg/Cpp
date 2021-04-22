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
void append_node_and_advance(shared_ptr<node_t<T>> &head, shared_ptr<node_t<T>> &tail, shared_ptr<node_t<T>> &n) {

    append_node(head, tail, n);
    n = n->next;
}

template <typename T>
shared_ptr<node_t<T>> merge_sorted_linked_lists(shared_ptr<node_t<T>> F, shared_ptr<node_t<T>> L) {

    shared_ptr<node_t<T>> sorted_head = nullptr, tail = nullptr;
    int i = 0;

    while (F && L) append_node_and_advance(sorted_head, tail, F->data < L->data ? F : L);

    // below two - append rest of the nodes
    if (F) append_node(sorted_head, tail, F);

    if (L) append_node(sorted_head, tail, L);

    return sorted_head;
}



int main() {

    auto f = make_node(1);
    auto l = make_node(2);
    auto tf = f, tl = l;

    for (int i = 3; i <= 10; ++i) {
        auto n = make_node(i);
        if (i % 2 != 0) append_node(f, tf, n);
        else append_node(l, tl, n);
    }

    print(f);
    print(l);

    auto sorted_head = merge_sorted_linked_lists(f, l);
    print(sorted_head);


}