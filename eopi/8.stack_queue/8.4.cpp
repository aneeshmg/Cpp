// print list in a 'jump-first' manner...postings list (linked list that has a random pointer) both recursivly and iteratively
#include <iostream>
#include <memory>
#include <stack>

using namespace std;

template <typename T>
class node_t {
    public:
        T data;
        shared_ptr<node_t<T>> next, jump;
        int order;
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
void search_posting_list_helper(const shared_ptr<node_t<T>> &L, int &order) {
    if (L && L->order) {
        L->order = order++;
        search_posting_list_helper(L->jump, order);
        search_posting_list_helper(L->next, order);
    }
}

template <typename T>
void search_posting_list(const shared_ptr<node_t<T>> &L) {
    int order = 0;
    search_posting_list_helper(L, order);
}

// iterative
template <typename T>
void search_posting_list_iterative(const shared_ptr<node_t<T>> &L) {
    stack<shared_ptr<node_t<T>>> s;
    int order;
    s.emplace(L);

    while (!s.empty()) {
        shared_ptr<node_t<T>> curr = s.top();
        s.pop();
        if (curr && curr->order == -1) {
            curr->order = order++;
            s.emplace(curr->next);
            s.emplace(curr->jump);
        }
    }
}

int main() {

    // test in rev
}