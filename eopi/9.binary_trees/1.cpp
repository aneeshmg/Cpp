// check if bin tree is balanced
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
int get_height(const shared_ptr<BinaryTree<T>> &n) {
    if (!n) return -1;

    int l_height = get_height(n->left);

    if (l_height == -2) return -2; // => left subtree is not balanced

    int r_height = get_height(n->right);

    if (r_height == -2) return -2; // => right subtree is not balanced

    if (abs(l_height - r_height) > 1) return -2; // main condition to check if balanced or not

    return max(l_height, r_height) + 1; // increment height as we are going one level down
}

template <typename T>
bool is_balanced(const shared_ptr<BinaryTree<T>> &n) {
    return get_height(n) != -2;
}

int main() {

    //
}