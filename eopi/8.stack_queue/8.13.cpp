// queue with max...just like stack with max
#include <iostream>
#include <stack>

template <typename T>
class Stack {
    private:
        stack<pair<T, T>> s;

    public:
        const bool empty(void) const {
            return s.empty();
        }

        const T &max(void) const {
            if (empty() == false) return s.top().second;

            throw length_error("empty stack");
        }

        T pop(void) {
            if (empty() == false) {
                T ret = s.top().first;
                s.pop();
                return ret;
            }
            throw length_error("empty stack");
        }

        void push(const T &x) {
            s.emplace(x, max(x, empty() ? x : s.top().second));
        }
};

using namespace std;

template <typename T>
class Queue {
    private:
        Stack<T> A, B;

    public:
        void enqueue(const T &x) {
            A.push(x);
        }

        T dequeue(void) {
            if (B.empty()) {
                while (A.empty() == false) {
                    B.push(A.top());
                    A.pop();
                }
            }
            if (B.empty() == false) return B.pop();

            throw length_error("empty queue");
        }

        const T &max(void) const {
            if (A.empty() == false) {
                return B.empty() ? A.max() : max(A.max(), B.max());
            } else { // A.empty() == true
                if (B.empty() == false) {
                    return B.max();
                }
                throw length_error("empty queue");
            }
        }
};

int main() {

    // fairly straightforward > utilizing recursion nicely
    // test in rev
}