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
void append_node(shared_ptr<node_t<T>> &head, shared_ptr<node_t<T>> &tail, shared_ptr<node_t<T>> &n) {
    head ? tail->next = n : n;
    tail = n;
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
shared_ptr<node_t<T>> make_node(T data) {
    shared_ptr<node_t<T>> temp(new node_t<T>());
    temp->data = data;
    temp->next = NULL;
    return temp;
}


int main() {

    // // this is wrong
    // node_t<int> *h = new node_t<int>();
    // h->data = 10;
    // h->next = NULL;

    shared_ptr<node_t<int>> head(new node_t<int>());
    head->data = 10;
    head->next = NULL;

    // shared_ptr<node_t<int>> tail(new node_t<int>());
    // tail->data = 20;
    // tail->next = NULL;

    shared_ptr<node_t<int>> tail = head;

    cout << head->data << " " << head->next << endl;

    print(head);

    auto n = make_node(20);
    append_node(head, tail, n);

    print(head);

    for (int i = 30; i <= 100; i += 10) {
        n = make_node(i);
        append_node(head, tail, n);
    }

    print(head);


}