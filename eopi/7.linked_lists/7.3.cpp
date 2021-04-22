// median of sorted circular list
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
double find_median_sorted_list(const shared_ptr<node_t<int>> &r_node) {
    if (!r_node) return 0.0;

    // check all nodes are identical or not and identify start of list
    shared_ptr<node_t<T>> curr = r_node, start = r_node;
    int count = 0;
    bool is_identical = true;

    do {
        if (curr->data != curr->next->data) is_identical = false;

        ++count, curr = curr->next;

        // start will point to largest element in the list
        if (start->data <= start->next->data) start = start->next;
    } while (curr != r_node);

    // if all values are equal, median = curr->data
    if (is_identical) return curr->data;

    // since start points to largest value now, its next is the start of the sorted list
    start = start->next; // start is now at the right place

    // now traverse to the mid of the list and return the median, notice the right shift in the line below
    for (int i = 0;  i < (count - 1) >> 1; ++i) {
        start = start->next;
    }

    // clever use of bitwise ops
    return count & 1 ? start->data : 0.5 * (start->data + start->next->data);

}


int main() {

    auto f = make_node(1);
    auto tf = f;

    for (int i = 2; i <= 10; ++i) {
        auto n = make_node(i);
        append_node(f, tf, n);
    }

    // create sorted loop and test in rev

    print(f);



}