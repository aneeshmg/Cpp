// given two lists, neither with loops, detect a node which is common to both (link node)
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
int count(const shared_ptr<node_t<T>> &head) {
    int l = 0;

    while (head) {
        ++l;
        head = head->next;
    }

    return l;
}

template <typename T>
void advance_list_by_k(shared_ptr<node_t<T>> &head, int k) {
    while (k--) {
        head = head->next;
    }
}

template <typename T>
shared_ptr<node_t<T>> find_overlap_node(shared_ptr<node_t<T>> L1, shared_ptr<node_t<T>> L2) {
    int L1_len = count<T>(L1), L2_len = count<T>(L2);

    // advance the longer list
    advance_list_by_k(L1_len > L2_len ? L1 : L2, abs(L2_len - L1_len));

    while (L1 && L2 && L1 != L2) {
        L1 = L1->next, L2 = L2->next;
    }

    return L1; // if nullptr, no overlap
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