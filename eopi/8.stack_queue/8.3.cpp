// print keys of BST in sorted order, no using recursion
#include <iostream>
#include <stack>
#include <memory>

template <typename T>
class BinarySearchTree {
    public:
        T data;
        shared_ptr<BinarySearchTree<T>> left, right;
};

template <typename T>
void print_BST_in_sorted_order(const shared_ptr<BinarySearchTree<T> &n) {
    stack<shared_ptr<BinarySearchTree<T>>> s;
    shared_ptr<BinarySearchTree<T>> curr = n;

    while (!s.empty() || curr) {
        if (curr) {
            s.push(curr);
            curr = curr->left;
        } else {
            curr = s.top();
            s.pop();
            cout << curr->data << endl;
            curr = curr->right;
        }
    }
}

using namespace std;

int main() {

    // fairly simple idea, test in rev
}