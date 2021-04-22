// same as 7.4 but both l1, l2 may have loops
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

template <typename T>
shared_ptr<node_t<T>> overlapping_lists(shared_ptr<node_t<T>> L1, shared_ptr<node_t<T>> L2) {

    // store start of cycle, if any
    shared_ptr<node_t<T>> s1 = has_cycle<T>(L1), s2 = has_cycle<T>(L2);

    if (!s1 && !s2) {
        return find_overlap_node(L1, L2);
    } else if (s1 && s2) { // both lists have cycles
        shared_ptr<node_t<T>> temp = s2; // doesnt matter whether u pick s1 or s2 here

        do {
            temp = temp->next;
        } while (temp != s1 && temp != s2);

        return temp == s1 ? s1 : nullptr;
    }

    return nullptr; // one list has cycle other doesn't
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