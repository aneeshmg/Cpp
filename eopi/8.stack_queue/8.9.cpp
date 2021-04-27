// print BST in level order without recursion
#include <iostream>
#include <memory>
#include <queue>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree<T>> left, right;
};

template <typename T>
void print_level_order_BT(const shared_ptr<BinaryTree<T>> &n) {
    if (!n) return;

    queue<shared_ptr<BinaryTree<T>>> q;

    q.emplace(n);
    while (!q.empty()) {
        cout << q.front()->data << ' ';

        if (q.front()->left) q.emplace(q.front()->left);
        if (q.front()->right) q.emplace(q.front()->right);

        q.pop();
    }
}

int main() {

    // test in rev
}