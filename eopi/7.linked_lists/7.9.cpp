// reverse a singly linked list
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
shared_ptr<node_t<T>> reverse_list_recursive(shared_ptr<node_t<T>> &head) {

    if (!head || !head->next) return head;

    shared_ptr<node_t<T>> new_head = reverse_list_recursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return new_head;
}

template <typename T>
shared_ptr<node_t<T>> reverse_list(shared_ptr<node_t<T>> &head) {

    shared_ptr<node_t<T>> prev = nullptr, curr = head;

    while (curr) {
        shared_ptr<node_t<T>> temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 10; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    print(f);

    f = reverse_list(f);

    print(f);

}