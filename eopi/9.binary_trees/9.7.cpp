// reconstruct binary tree given inorder & pre/post order traversals
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right;
};

template <typename T>
shared_ptr<BinaryTree<T>> reconstruct_pre_in_orders_helper(const vector<T> &pre, const int &pre_s, const int pre_e,
    const vector<T> &in, const int &in_s, const int in_e) {

    if (pre_e > pre_s && in_e > in_s) {
        auto it = find(in.cbegin() + in_s, in.cbegin() + in_e, pre[pre_s]);
        int left_tree_size = it - (in.cbegin() + in_s);

        return shared_ptr<BinaryTree<T>>(new BinaryTree<T> {
            pre[pre_s],
            // recursively build the left subtree
            reconstruct_pre_in_orders_helper<T>(
                pre, pre_s + 1, pre_s + 1 + left_tree_size,
                in, in_s, it - in.cbegin()
            ),
            // recursively build the right subtree
            reconstruct_pre_in_orders_helper<T>(
                pre, pre_s + 1 + left_tree_size, pre_e,
                in, it - in.cbegin() + 1, in_e
            )
        });
    }
    return nullptr;
}

template <typename T>
shared_ptr<BinaryTree<T>> reconstruct_pre_in_orders(const vector<T> &pre, const vector<T> &in) {
    return reconstruct_pre_in_orders_helper(pre, 0, pre.size(), in, 0, in.size());
}

template <typename T>
shared_ptr<BinaryTree<T>> reconstruct_post_in_orders_helper(const vector<T> &post, const int &post_s, const int post_e,
    const vector<T> &in, const int &in_s, const int in_e) {
    if (post_e > post_s && in_e > in_s) {
        auto it = find(in.cbegin() + in_s, in.cbegin() + in_e, post[post_e - 1]);
        int left_tree_size = it - (in.cbegin() + in_s);

        return shared_ptr<BinaryTree<T>>(new BinaryTree<T> {
            post[post_e - 1],
            // recursively build the left subtree
            reconstruct_post_in_orders_helper<T>(
                post, post_s, post_s + left_tree_size,
                in, in_s, it - in.cbegin()
            ),
            // recursively build right subtree
            reconstruct_post_in_orders_helper<T>(
                post, post_s + left_tree_size, post_e - 1,
                in, it - in.cbegin() + 1, in_e
            )
        });
    }
    return nullptr;

}

template <typename T>
shared_ptr<BinaryTree<T>> reconstruct_post_in_orders(const vector<T> &post, const vector<T> &in) {
    return reconstruct_post_in_orders_helper(post, 0, post.size(), in, 0, in.size());
}

int main() {

    // no idea how this is working...research on lc
}