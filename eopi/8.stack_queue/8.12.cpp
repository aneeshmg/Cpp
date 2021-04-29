// queue using 2 stacks, optimal implementation
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Queue {
    private:
        stack<T> A, B;

    public:
        void enqueue(const T &x) {
            A.emplace(x);
        }

        T dequeue(void) {
            if (B.empty()) {
                while (!A.empty()) {
                    B.emplace(A.top());
                    A.pop();
                }
            }
            if (B.empty() == false) {
                T ret = B.top();
                B.pop();
                return ret;
            }
            throw length_error("empty queue");
        }
};

int main() {

    // fairly straightforward 
    // test in rev
}