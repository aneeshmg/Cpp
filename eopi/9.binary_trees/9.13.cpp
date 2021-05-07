// optimized LCA (in 12th prob, we travel all the way up to the root while computing the depth(s))
#include <iostream>
#include <memory>
#include <unordered_set>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right, parent;
};

template <typename T>
shared_ptr<BinaryTree<T>> LCA(shared_ptr<BinaryTree<T>> a, shared_ptr<BinaryTree<T>> b) {
    unordered_set<shared_ptr<BinaryTree<T>>> hash;

    while (a || b) {
        if (a) {
            if (hash.emplace(a).second == false) {
                return a; // adds a failed as a exists in hash
            }
            a = a->parent;
        }
        if (b) {
            if (hash.emplace(b).second == false) {
                return b; // adds b failed as b exiss in hash
            }
            b = b->parent;
        }
    }
    throw length_error("doesn't exist");
}

int main() {

    // simple
}