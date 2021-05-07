// print exterior of BT in anticlockwise manner
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
void left_boundary_tree(const shared_ptr<BinaryTree<T>> &n, const bool &is_boundary) {
    if (n) {
        if (is_boundary || (!n->left && !n->right)) {
            cout << n->data << ' ';
        }

        left_boundary_tree(n->left, is_boundary);
        left_boundary_tree(n->right, is_boundary && !n->left);
    }
}

template <typename T>
void right_boundary_tree(const shared_ptr<BinaryTree<T>> &n, const bool &is_boundary) {
    if (n) {
        right_boundary_tree(n->left, is_boundary && !n->right);
        right_boundary_tree(n->right, is_boundary);

        if (is_boundary || (!n->left && !n->right)) {
            cout << n->data << ' ';
        }
    }
}

template <typename T>
void exterior_binary_tree(const shared_ptr<BinaryTree<T>> &root) {
    cout << root->data << ' ';
    left_boundary_tree(root->left, true);
    right_boundary_tree(root->right, true);
}

int main() {

    //
}