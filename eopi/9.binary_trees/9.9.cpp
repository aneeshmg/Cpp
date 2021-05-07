// form a linked list from leaves of a binary tree
#include <iostream>
#include <memory>
#include <list>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right;
};

template <typename T>
void connect_leaves_helper(const shared_ptr<BinaryTree<T>> &n, list<shared_ptr<BinaryTree<T>>> &L) {
    if (n) {
        if (!n->left && !n->right) {
            L.push_back(n);
        } else {
            connect_leaves_helper(n->left, L);
            connect_leaves_helper(n->right, L);
        }
    }
}

template <typename T>
list<shared_ptr<BinaryTree<T>>> connect_leaves(const shared_ptr<BinaryTree<T>> &n) {
    list<shared_ptr<BinaryTree<T>>> L;

    connect_leaves_helper(n, L);

    return L;
}

int main() {

    // pretty straightforward
}