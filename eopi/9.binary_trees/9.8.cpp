// reconstruct binary tree given preorder with nulls if empty children
#include <iostream>
#include <memory>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right;
};

template <typename T>
shared_ptr<BinaryTree<T>> reconstruct_preorder(const vector<shared_ptr<T>> &preorder) {
    stack<shared_ptr<BinaryTree<T>>> s;

    for (auto it = preorder.crbegin(); it != preorder.crend(); ++it) {
        if (!(*it)) {
            s.emplace(nullptr);
        } else { // non-null
            shared_ptr<BinaryTree<T>> l = s.top();
            s.pop();
            shared_ptr<BinaryTree<T>> r = s.top();
            s.pop();
            s.emplace(new BinaryTree<T>{*(*it), l, r});
        }
    }
    return s.top();
}

int main() {

    // solution doesn't make sense...look up lc
}