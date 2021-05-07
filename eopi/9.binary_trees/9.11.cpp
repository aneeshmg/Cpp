// compute lowest common ancestor
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
shared_ptr<BinaryTree<T>> LCA(const shared_ptr<BinaryTree<T>> &n, const shared_ptr<BinaryTree<T>> &a, const shared_ptr<BinaryTree<T>> &b) {
    if (!n) {
        return nullptr;
    } else if (n == a || n == b) {
        return n;
    }

    auto l_res = LCA(n->left, a, b), r_res = LCA(n->right, a, b);
    if (l_res && r_res) {
        return n; // found a & b in different sub trees
    } else {
        return l_res ? l_res : r_res;
    }
}

int main() {

    // needs more research...
}