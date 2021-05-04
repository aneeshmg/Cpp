// locking of nodes in binary tree
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class BinaryTree {
    private:
        bool locked;
        int numChildrenLocks;
    public:
        T data;
        shared_ptr<BinaryTree> left, right, parent;

        const bool &isLocked(void) const {
            return locked;
        }
        void lock(void) {
            if (numChildrenLocks == 0 && locked = false) {
                // make sure all parents do not lock
                shared_ptr<BinaryTree<T>> n = parent;
                while (n) {
                    if (n->locked == true) return;
                    n = n->parent;
                }

                // lock self and update parents
                locked = true;
                n = parent;
                while (n) {
                    ++n->numChildrenLocks;
                    n = n->parent;
                }
            }
        }
        void unlock(void) {
            if (locked) {
                // unlock self and update parents
                locked = false;
                shared_ptr<BinaryTree<T>> n = parent;
                while (n) {
                    --n->numChildrenLocks;
                    n = n->parent;
                }
            }
        }
};


int main() {

    // seems silly...
}