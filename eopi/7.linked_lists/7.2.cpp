// detect cycle in list
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
shared_ptr<node_t<T>> has_cycle(const shared_ptr<node_t<T>> &head) {
    shared_ptr<node_t<T>> fast = head, slow = head;

    while (slow && slow->next && fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        // if cycle found
        if (slow == fast) {
            int cycle_length = 0;
            do {
                ++cycle_length;
                fast = fast->next;
            } while (slow != fast);

            // now to find start of the cycle
            slow = head, fast = head;
            while (cycle_length--) fast = fast->next;

            // now advance both pointers
            while (slow != fast)
                slow = slow->next, fast = fast->next;

            return slow;
        }
    }

    return nullptr;
}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 10; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    // create loop and test in rev

    print(f);



}