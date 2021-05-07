// LCA given parent pointer
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right, parent;
};

template <typename T>
int get_depth(shared_ptr<BinaryTree<T>> n) {
    int d = 0;
    while (n) {
        ++d;
        n = n->parent;
    }
    return d;
}

template <typename T>
shared_ptr<BinaryTree<T>> LCA(const shared_ptr<BinaryTree<T>> a, const shared_ptr<BinaryTree<T>> b) {
    int depth_a = get_depth(a), depth_b = get_depth(b);

    if (depth_b > depth_a) {
        swap(a, b);
    }

    // advance deeper node first
    // now a is deeper
    int depth_diff = depth_a - depth_b;
    while (depth_diff--) {
        a = a->parent;
    }

    while (a != b) {
        a = a->parent, b = b->parent; // advance both nodes to parent, and when they are equal that will be the LCA
    }

    return a;
}

int main() {

    // fairly intuitive
}