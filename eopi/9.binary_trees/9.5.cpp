// in order traversal of bin tree with O(1) space
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
void inorder_traversal(const shared_ptr<BinaryTree<T>> &r) {
    if (!r) return;

    shared_ptr<BinaryTree<T>> prev = nullptr, curr = r, next;
    while (curr) {
        if (!prev || prev->left == curr || prev->right == curr) {
            if (curr->left)
                next = curr->left;
            else {
                cout << curr->data << endl;
                next = (curr->right ? curr->right : curr->parent);
            }
        } else if (curr->left == prev) {
            cout << curr->data << endl;
            next = (curr->right ? curr->right : curr->parent);
        } else {
            next = curr->parent;
        }

        prev = curr;
        curr = next;
    }
}

int main() {

    // space becomes O(height) with recursion. If you do iterative, with stack, it still becomes O(height)
    // morris traversal
}