#include <iostream>
#include <stack>

using namespace std;

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

int main() {

    // fairly straightforward
}