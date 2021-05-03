// check if bin tree is symmetric...ie mirrorred about the root-axis
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right;
};

template <typename T>
bool is_symmetric_helper(const shared_ptr<BinaryTree<T>> &l, const shared_ptr<BinaryTree<T>> &r) {
    if (!l && !r) return true;

    else if (l && r) {
        return l->data == r->data && is_symmetric_helper<T>(l->left, r->right) && is_symmetric_helper<T>(l->right, r->left);
    } else {
        return false;
    }
}

template <typename T>
bool is_symmetric(const shared_ptr<BinaryTree<T>> &n) {
    return (!n || is_symmetric_helper<T>(n->left, n->right));
}

int main() {

    // simple enough logic
}