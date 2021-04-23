// given a list and a node, delete the node from the list
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

template <typename T>
void connect_a_to_b_advance_a(shared_ptr<node_t<T>> &a, const shared_ptr<node_t<T>> &b) {
    shared_ptr<node_t<T>> temp = a->next;
    a->next = b;
    a = temp;
}

template <typename T>
shared_ptr<node_t<T>> zip_list(const shared_ptr<node_t<T>> &L) {
    shared_ptr<node_t<T>> slow = L, fast = L, pre_slow = nullptr;

    // find the midpoint of L
    while (fast) {
        fast = fast->next;
        if (fast) {
            pre_slow = slow;
            slow = slow->next, fast = fast->next;
        }
    }

    if (!pre_slow) {
        return L; // only one node in the list
    }

    pre_slow->next = nullptr;
    shared_ptr<node_t<T>> reverse = reverse_list<T>(slow), curr = L;

    // now start zipping
    while (curr && reverse) {
        // connect reverse to curr->next and advance curr
        connect_a_to_b_advance_a(curr, reverse);
        if (curr) {
            // connect reverse->next to curr and advance reverse
            connect_a_to_b_advance_a(reverse, curr);
        }
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

    // need to test

    print(f);

}