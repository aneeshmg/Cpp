// remove kth last element
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
void delete_kth_node(shared_ptr<node_t<T>> &L, const int &k) {

    shared_ptr<node_t<T>> ahead = L;
    int num = k;

    while (ahead && num--) {
        ahead = ahead->next;
    }

    if (num > 0) throw length_error("not enough nodes in the list");

    shared_ptr<node_t<T>> pre = nullptr, curr = L;
    // go to the kth last node
    while (ahead) {
        pre = curr; // at the end of the loop, pre is at the kth from the last node
        curr = curr->next, ahead = ahead->next;
    }

    if (pre) pre->next = curr->next;
    else L = curr->next; // special case? what is special, why?

}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 10; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    print(f);

    delete_kth_node(f, 3);

    print(f);

}