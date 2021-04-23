// clone list with random/jump pointer
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
class node_t {
    public:
        T data;
        shared_ptr<node_t<T>> next, jump;
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
void connect_via_jump(shared_ptr<node_t<T>> &a, const shared_ptr<node_t<T>> &b) {
    a->jump = b;
}

template <typename T>
shared_ptr<node_t<T>> copy_postings_list(const shared_ptr<node_t<T>> &L) {
    // return empty list if L is nullptr
    if (!L) return nullptr;

    // this is not the only way to do this
    // stage 1: copy nodes from L
    shared_ptr<node_t<T>> p = L;
    while (p) {
        auto temp = shared_ptr<node_t<T>>(new node_t<T>{p->data, p->next, nullptr});
        p->next = temp;
        p = temp->next;
    }

    // 2nd stage: update the jump fields
    p = L;
    while (p) {
        if (p->jump) {
            p->next->jump = p->jump->next;
        }
        p = p->next->next;
    }

    // stage3: update the next field
    p = L;
    shared_ptr<node_t<T>> copied = p->next;
    while (p->next) {
        shared_ptr<node_t<T>> temp = p->next;
        p->next = temp->next;
        p = temp;
    }

    return copied;
}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 10; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    // test in rev

    print(f);

}