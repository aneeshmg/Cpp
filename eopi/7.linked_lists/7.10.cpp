// check if a list is a palindrome
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
bool is_palindrome(shared_ptr<node_t<T>> L) {

    // find the mid point
    shared_ptr<node_t<T>> slow = L, fast = L;

    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next, slow = slow->next;
        }
    }

    shared_ptr<node_t<T>> reversed_list = reverse_list<T>(slow);
    while (reversed_list && L) {
        if (reversed_list->data != L->data) {
            return false;
        }
        reversed_list = reversed_list->next, L = L->next;
    }

    return true;
}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 5; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }
    for (int i = 5; i >= 1; --i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    print(f);

    cout << is_palindrome(f) << endl;

}