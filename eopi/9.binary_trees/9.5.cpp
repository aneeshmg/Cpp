// in order traversal find kth node
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right, parent;
        int size;
};

template <typename T>
shared_ptr<BinaryTree<T>> find_kth_node_binary_tree(const shared_ptr<BinaryTree<T>> &r, int k) {
    while (k && r) {
        int left_size = r->left ? r->left->size : 0;
        if (left_size < k - 1) {
            k -= (left_size + 1);
            r = r->right;
        } else if (left_size == k - 1) {
            return r;
        } else { // left size > k - 1
            r = r->left;
        }
    }
    throw length_error("no k-th node in tree");
}

int main() {

    // space becomes O(height) with recursion. If you do iterative, with stack, it still becomes O(height)
    // morris traversal
}