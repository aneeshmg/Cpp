// check if bin tree is k-balanced (ie diff btw r_height and l_height is no more than k)
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
pair<shared_ptr<BinaryTree<T>>, int> find_non_k_balanced_node_helper(const shared_ptr<BinaryTree<T>> &n, const int &k) {
    if (!n) return {nullptr, 0};

    auto L = find_non_k_balanced_node_helper(n->left, k);
    if (L.first) return L;

    auto R = find_non_k_balanced_node_helper(n->right, k);
    if (R->first) return R;

    int node_num = L.second + R.second + 1; // counting nodes in n
    if (abs(L.second - R.second) > k) {
        return {n, node_num};
    }

    return {nullptr, node_num};
}

template <typename T>
shared_ptr<BinaryTree<T>> find_non_k_balanced_node(const shared_ptr<BinaryTree<T>> &n, const int &k) {
    return find_non_k_balanced_node_helper(n, k).first;
}

int main() {

    //
}