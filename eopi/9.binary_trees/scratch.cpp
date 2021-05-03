#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class BinaryTree {
    public:
        T data;
        shared_ptr<BinaryTree> left, right;
};

int main() {

    cout << "Scratch pad.." << endl;
}